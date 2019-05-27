package org.cocos2dx.lib;

import android.util.Log;

import java.io.BufferedInputStream;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.ConnectException;
import java.net.SocketTimeoutException;
import java.net.UnknownHostException;
import java.security.KeyManagementException;
import java.security.KeyStore;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.NoSuchProviderException;
import java.security.SecureRandom;
import java.security.UnrecoverableKeyException;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

import javax.net.ssl.KeyManager;
import javax.net.ssl.KeyManagerFactory;
import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManager;
import javax.net.ssl.TrustManagerFactory;
import javax.net.ssl.X509TrustManager;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import okhttp3.WebSocket;
import okhttp3.WebSocketListener;
import okio.ByteString;

@SuppressWarnings("unused")
public class Cocos2dxWebSocket {

    private static WebSocketClientWrap __defaultClient = null;

    private static AtomicLong __connectionIdGenerator = new AtomicLong(10000);

    private static Map<Long, WebSocketWrap> __socketMap = new ConcurrentHashMap<>();

    private static Map<String, WebSocketClientWrap> __secureClientCache = new ConcurrentHashMap<>();

    private static final class WebSocketClientWrap {
        WebSocketClientWrap(OkHttpClient client, boolean defaultClient) {
            this._client = client;
            this._refCount = new AtomicInteger(0);
            this._isDefaultClient = defaultClient;
        }

        void retain() {
            this._refCount.incrementAndGet();
        }

        void release() {
            if(this._refCount.decrementAndGet() <= 0) {
                this.shutdown();
            }
        }

        void shutdown() {
            if(this._client!=null) {
                this._client.dispatcher().executorService().shutdown();
                for(String key : __secureClientCache.keySet()) {
                    if(__secureClientCache.get(key) == this) {
                        __secureClientCache.remove(key);
                    }
                }
                this._client = null;
            }
        }

        OkHttpClient getClient() {
            return _client;
        }

        private OkHttpClient _client;
        private AtomicInteger _refCount;
        private boolean _isDefaultClient;
    }

    private static final class WebSocketWrap {

        WebSocketWrap(WebSocket socket, WebSocketClientWrap client) {
            this._socket = socket;
            this._client = client;
        }

        public void close(boolean syncClose)
        {
            this._closed = true;
            this._syncClose = syncClose;
            this._socket.close(1000, "manually close by client");
        }

        public void send(String text) {
            this._socket.send(text);
        }

        public void send(ByteString bs)
        {
            this._socket.send(bs);
        }

        private WebSocket _socket;
        private boolean _syncClose = false;
        private boolean _closed = false;
        private WebSocketClientWrap _client;

    }

    private static final class LocalWebSocketListener extends WebSocketListener {

        private long _connectionID;

        LocalWebSocketListener(long cid) {
            this._connectionID = cid;
        }

        @Override
        public void onOpen(WebSocket webSocket, Response response) {
            WebSocketWrap wrap = __socketMap.get(_connectionID);
            if(wrap != null && wrap._closed) return;
            triggerEventDispatch(_connectionID, "open", response.message(), false);
        }

        @Override
        public void onMessage(WebSocket webSocket, String text) {
            WebSocketWrap wrap = __socketMap.get(_connectionID);
            if(wrap != null && wrap._closed) return;

            triggerEventDispatch(_connectionID, "message", text, false);
        }

        @Override
        public void onMessage(WebSocket webSocket, ByteString bytes) {
            WebSocketWrap wrap = __socketMap.get(_connectionID);
            if(wrap != null && wrap._closed) return;
            triggerEventDispatch(_connectionID, "message", bytes.toString(), true);
        }

        @Override
        public void onClosing(WebSocket webSocket, int code, String reason) {
            WebSocketWrap wrap = __socketMap.get(_connectionID);
            if(wrap != null && wrap._closed) return;
            triggerEventDispatch(_connectionID, "closing", reason, false);
        }

        @Override
        public void onClosed(WebSocket webSocket, int code, String reason) {
            WebSocketWrap wrap = __socketMap.get(_connectionID);
            if(wrap != null && wrap._syncClose) {
                //This procedure DOES NOT run in GL thread, so that this message will not be blocked
                //in task queue.
                triggerEvent(_connectionID, "sync-_closed", "", false);
            }else {
                triggerEventDispatch(_connectionID, "_closed", reason, false);
            }
            if(wrap != null) {
                wrap._client.release();
            }
            __socketMap.remove(_connectionID);
        }

        @Override
        public void onFailure(WebSocket webSocket, Throwable t, Response response) {
            WebSocketWrap wrap = __socketMap.get(_connectionID);

            if(t instanceof UnknownHostException) {
                triggerEventDispatch(_connectionID, "error", "CONNECTION_FAILURE", false);
            } else if (t instanceof  SocketTimeoutException) {
                triggerEventDispatch(_connectionID, "error", "TIME_OUT", false);
            } else if (t instanceof ConnectException) {
                triggerEventDispatch(_connectionID, "error", "CONNECTION_FAILURE", false);
            } else {
                triggerEventDispatch(_connectionID, "error", t.getMessage(), false);
            }
            if(wrap != null) {
                wrap._client.release();
            }
            __socketMap.remove(_connectionID);
        }
    }

    private static okhttp3.OkHttpClient.Builder newClientBuilder() {
        OkHttpClient.Builder builder = new OkHttpClient.Builder();
        builder.connectTimeout(40, TimeUnit.SECONDS)
                .readTimeout(40, TimeUnit.SECONDS)
                .writeTimeout(40, TimeUnit.SECONDS);
        return builder;
    }

    private static WebSocketClientWrap getDefaultClient() {
        if(__defaultClient == null) {
            OkHttpClient client = newClientBuilder().build();
            __defaultClient = new WebSocketClientWrap(client, true);
            __defaultClient.retain(); //prevent shutdown by default
        }
        return __defaultClient;
    }

    private static OkHttpClient.Builder configSSL(String caContent, OkHttpClient.Builder builder)  {
        if(caContent == null || caContent.isEmpty()) return null;
        ByteArrayInputStream is = null;
        BufferedInputStream bis = null;
        try {
            KeyStore ks = KeyStore.getInstance(KeyStore.getDefaultType());
            ks.load(null, null);

            is = new ByteArrayInputStream(caContent.getBytes());
            bis = new BufferedInputStream(is);

            CertificateFactory cff;

            //use provider "BC" by default
            try {
                cff =  CertificateFactory.getInstance("X.509", "BC");
            } catch (NoSuchProviderException e) {
                e.printStackTrace();
                cff =  CertificateFactory.getInstance("X.509");
            }


            while(bis.available() > 0) {
                X509Certificate ce = (X509Certificate)cff.generateCertificate(bis);
                String alias = ce.getSubjectX500Principal().getName();
                ks.setCertificateEntry(alias, ce);
            }

            TrustManagerFactory tmf = TrustManagerFactory.getInstance(TrustManagerFactory.getDefaultAlgorithm());
            tmf.init(ks);
            TrustManager[] trustManagers = tmf.getTrustManagers();

            KeyManagerFactory kmf = KeyManagerFactory.getInstance(KeyManagerFactory.getDefaultAlgorithm());
            kmf.init(ks, null);
            KeyManager[] keyManagers = kmf.getKeyManagers();

            SSLContext ctx = SSLContext.getInstance("TLS");
            ctx.init(keyManagers, trustManagers, new SecureRandom());

            builder.sslSocketFactory(ctx.getSocketFactory(), (X509TrustManager)trustManagers[0]);
            return builder;
        } catch (KeyStoreException e) {
            e.printStackTrace();
        } catch (CertificateException e) {
            e.printStackTrace();
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (UnrecoverableKeyException e) {
            e.printStackTrace();
        } catch (KeyManagementException e) {
            e.printStackTrace();
        } finally {
            if(is!=null) {
                try {
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if(bis != null) {
                try {
                    bis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return null;
    }

    public static long connect(String url, String[] protocals, String caContent) {
        Request.Builder requestBuilder = new Request.Builder();
        if(protocals != null && protocals.length > 0) {
            //join string
            StringBuilder buffer = new StringBuilder();
            for(int i = 0; i < protocals.length - 1; i ++) {
                buffer.append(protocals[i]);
                buffer.append("; ");
            }
            buffer.append(protocals[protocals.length - 1]);
            requestBuilder.addHeader("Sec-WebSocket-Protocol", buffer.toString());
        }

        OkHttpClient.Builder clientBuilder = null;
        WebSocketClientWrap clientWrap = null;

        if(caContent != null && !caContent.isEmpty()) {
            if(__secureClientCache.containsKey(caContent) ){
                clientWrap = __secureClientCache.get(caContent);
            }else {
                clientBuilder = newClientBuilder();
                clientBuilder = configSSL(caContent, clientBuilder);
                if (clientBuilder != null) {
                    clientWrap = new WebSocketClientWrap(clientBuilder.build(), false);
                    __secureClientCache.put(caContent, clientWrap);
                }
            }
        }

        if(clientWrap == null){
            clientWrap = getDefaultClient();
        }

        long connectionId = __connectionIdGenerator.incrementAndGet();
        Request request = requestBuilder.url(url).build();
        LocalWebSocketListener listener = new LocalWebSocketListener(connectionId);
        WebSocket socket = clientWrap.getClient().newWebSocket(request, listener);
        __socketMap.put(connectionId, new WebSocketWrap(socket, clientWrap));

        clientWrap.retain();

        return connectionId;
    }

    public static void disconnect(long connectionID, boolean syncClose) {
        WebSocketWrap socket = __socketMap.get(connectionID);
        if(socket != null) {
            socket.close(syncClose);
        }else {
            Log.e("[WebSocket]", "_socket "+connectionID + " not found!");
        }
    }

    public static void sendBinary(long connectionID, byte[] message)
    {
        WebSocketWrap socket = __socketMap.get(connectionID);
        if(socket != null) {
            socket.send(ByteString.of(message));
        }else {
            Log.e("[WebSocket]", "_socket "+connectionID + " not found!");
        }
    }

    public static void sendString(long connectionID, String message)
    {
        WebSocketWrap socket = __socketMap.get(connectionID);
        if(socket != null) {
            socket.send(message);
        }else {
            Log.e("[WebSocket]", "_socket "+connectionID + " not found!");
        }
    }

    private static void triggerEventDispatch(final long connectionID, final String eventName, final String data, final boolean isBinary)
    {
        ((Cocos2dxActivity)Cocos2dxHelper.getActivity()).runOnGLThread(new Runnable() {
            @Override
            public void run() {
                triggerEvent(connectionID, eventName, data, isBinary);
            }
        });

    }

    static native void triggerEvent(long connectionID, String eventName, String data, boolean isBinary);

}
