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
import java.security.SecureRandom;
import java.security.UnrecoverableKeyException;
import java.security.cert.Certificate;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;
import java.util.Collection;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

import javax.net.ssl.KeyManager;
import javax.net.ssl.KeyManagerFactory;
import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManager;
import javax.net.ssl.TrustManagerFactory;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import okhttp3.WebSocket;
import okhttp3.WebSocketListener;
import okio.ByteString;

@SuppressWarnings("unused")
public class Cocos2dxWebSocket {

    private static okhttp3.OkHttpClient _client = null;

    private static AtomicLong connectionIdGenerator = new AtomicLong(10000);

    private static Map<Long, WebSocketWrap> socketMap = new ConcurrentHashMap<>();

    private static final class WebSocketWrap {

        WebSocketWrap(WebSocket socket) {
            this.socket = socket;
        }

        public void close(boolean syncClose)
        {
            this.closed = true;
            this.syncClose = syncClose;
            this.socket.close(1000, "manually close by client");
        }

        public void send(String text) {
            this.socket.send(text);
        }

        public void send(ByteString bs)
        {
            this.socket.send(bs);
        }

        private WebSocket socket;
        private boolean syncClose = false;
        private boolean closed = false;

    }

    private static final class LocalWebSocketListener extends WebSocketListener {

        private long connectionID;

        LocalWebSocketListener(long cid) {
            this.connectionID = cid;
        }

        @Override
        public void onOpen(WebSocket webSocket, Response response) {
            WebSocketWrap wrap = socketMap.get(connectionID);
            if(wrap != null && wrap.closed) return;
            triggerEventDispatch(connectionID, "open", response.message(), false);
        }

        @Override
        public void onMessage(WebSocket webSocket, String text) {
            WebSocketWrap wrap = socketMap.get(connectionID);
            if(wrap != null && wrap.closed) return;

            triggerEventDispatch(connectionID, "message", text, false);
        }

        @Override
        public void onMessage(WebSocket webSocket, ByteString bytes) {
            WebSocketWrap wrap = socketMap.get(connectionID);
            if(wrap != null && wrap.closed) return;
            triggerEventDispatch(connectionID, "message", bytes.toString(), true);
        }

        @Override
        public void onClosing(WebSocket webSocket, int code, String reason) {
            WebSocketWrap wrap = socketMap.get(connectionID);
            if(wrap != null && wrap.closed) return;
            triggerEventDispatch(connectionID, "closing", reason, false);
        }

        @Override
        public void onClosed(WebSocket webSocket, int code, String reason) {
            WebSocketWrap wrap = socketMap.get(connectionID);
            if(wrap != null && wrap.syncClose) {
                //This procedure DOES NOT run in GL thread, so that this message will not be blocked
                //in task queue.
                triggerEvent(connectionID, "sync-closed", "", false);
            }else {
                triggerEventDispatch(connectionID, "closed", reason, false);
            }

            socketMap.remove(connectionID);
        }

        @Override
        public void onFailure(WebSocket webSocket, Throwable t, Response response) {
            if(t instanceof UnknownHostException) {
                triggerEventDispatch(connectionID, "error", "CONNECTION_FAILURE", false);
            } else if (t instanceof  SocketTimeoutException) {
                triggerEventDispatch(connectionID, "error", "TIME_OUT", false);
            } else if (t instanceof ConnectException) {
                triggerEventDispatch(connectionID, "error", "CONNECTION_FAILURE", false);
            } else {
                triggerEventDispatch(connectionID, "error", t.getMessage(), false);
            }
            socketMap.remove(connectionID);
        }
    }

    private static okhttp3.OkHttpClient getClient() {
        if(_client == null) {
            OkHttpClient.Builder builder = new OkHttpClient.Builder();
            builder.connectTimeout(40, TimeUnit.SECONDS)
                    .readTimeout(40, TimeUnit.SECONDS)
                    .writeTimeout(40, TimeUnit.SECONDS);
            _client = builder.build();
        }
        return _client;
    }

    private static SSLContext buildSSlContext(String caContent)  {
        if(caContent == null || caContent.isEmpty()) return null;
        ByteArrayInputStream is = null;
        BufferedInputStream bis = null;
        try {
            KeyStore ks = KeyStore.getInstance("PKCS12");
            ks.load(null, null);

            is = new ByteArrayInputStream(caContent.getBytes());
            bis = new BufferedInputStream(is);

            CertificateFactory cff = CertificateFactory.getInstance("X509");
//            while(bis.available() > 0) {
//                X509Certificate ce = (X509Certificate)cff.generateCertificate(bis);
//                String alias = ce.getSubjectX500Principal().getName();
//                ks.setCertificateEntry(alias, ce);
//            }

            Collection<? extends Certificate> certList = cff.generateCertificates(bis);
            for(Certificate ce: certList) {
                if(ce instanceof X509Certificate) {
                    String alias = ((X509Certificate)ce).getSubjectX500Principal().getName();
                    ks.setCertificateEntry(alias, ce);
                }else{
                    Log.e("[Websocket]", "invalidate certificate format " + ce.getClass().getSimpleName());
                }
            }


            TrustManagerFactory tmf = TrustManagerFactory.getInstance(TrustManagerFactory.getDefaultAlgorithm());
            tmf.init(ks);
            TrustManager[] trustManagers = tmf.getTrustManagers();

            KeyManagerFactory kmf = KeyManagerFactory.getInstance(KeyManagerFactory.getDefaultAlgorithm());
            kmf.init(ks, null);
            KeyManager[] keyManagers = kmf.getKeyManagers();

            SSLContext ctx = SSLContext.getInstance("TLS");
            ctx.init(keyManagers, trustManagers, new SecureRandom());

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
        Request.Builder builder = new Request.Builder();
        if(protocals != null && protocals.length > 0) {
            //join string
            StringBuilder buffer = new StringBuilder();
            for(int i = 0; i < protocals.length - 1; i ++) {
                buffer.append(protocals[i]);
                buffer.append("; ");
            }
            buffer.append(protocals[protocals.length - 1]);
            builder.addHeader("Sec-WebSocket-Protocol", buffer.toString());
        }


        //TODO set self-signed CA
        SSLContext ctx = buildSSlContext(caContent);

        long connectionId = connectionIdGenerator.incrementAndGet();
        Request request = builder.url(url).build();
        LocalWebSocketListener listener = new LocalWebSocketListener(connectionId);
        WebSocket socket = getClient().newWebSocket(request, listener);

        socketMap.put(connectionId, new WebSocketWrap(socket));
        return connectionId;
    }

    public static void disconnect(long connectionID, boolean syncClose) {
        WebSocketWrap socket = socketMap.get(connectionID);
        if(socket != null) {
            socket.close(syncClose);
        }else {
            Log.e("[WebSocket]", "socket "+connectionID + " not found!");
        }
    }

    public static void sendBinary(long connectionID, byte[] message)
    {
        WebSocketWrap socket = socketMap.get(connectionID);
        if(socket != null) {
            socket.send(ByteString.of(message));
        }else {
            Log.e("[WebSocket]", "socket "+connectionID + " not found!");
        }
    }

    public static void sendString(long connectionID, String message)
    {
        WebSocketWrap socket = socketMap.get(connectionID);
        if(socket != null) {
            socket.send(message);
        }else {
            Log.e("[WebSocket]", "socket "+connectionID + " not found!");
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
