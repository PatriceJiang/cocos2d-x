package org.cocos2dx.lib;

import android.util.Log;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.atomic.AtomicLong;

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

    private static Map<Long, WebSocket> socketMap = new ConcurrentHashMap<>();

    private static final class LocalWebSocketListener extends WebSocketListener {

        private long connectionID;

        LocalWebSocketListener(long cid) {
            this.connectionID = cid;
        }

        @Override
        public void onOpen(WebSocket webSocket, Response response) {
            triggerEventDispatch(connectionID, "open", response.message(), false);
        }

        @Override
        public void onMessage(WebSocket webSocket, String text) {
            triggerEventDispatch(connectionID, "message", text, false);
        }

        @Override
        public void onMessage(WebSocket webSocket, ByteString bytes) {
            triggerEventDispatch(connectionID, "message", bytes.toString(), true);
        }

        @Override
        public void onClosing(WebSocket webSocket, int code, String reason) {
            triggerEventDispatch(connectionID, "closing", reason, false);
        }

        @Override
        public void onClosed(WebSocket webSocket, int code, String reason) {

            //This procedure DOES NOT run in GL thread, so that this message will not be blocked
            //in task queue.
            triggerEvent(connectionID, "sync-closed", "", false);

            triggerEventDispatch(connectionID, "closed", reason, false);
        }

        @Override
        public void onFailure(WebSocket webSocket, Throwable t, Response response) {
            triggerEventDispatch(connectionID, "error", t.getMessage(), false);
        }
    }

    private static okhttp3.OkHttpClient getClient() {
        if(_client != null) {
            OkHttpClient.Builder builder = new OkHttpClient.Builder();
            builder.connectTimeout(40, TimeUnit.SECONDS)
                    .readTimeout(40, TimeUnit.SECONDS)
                    .writeTimeout(40, TimeUnit.SECONDS);
            _client = builder.build();
        }
        return _client;
    }

    public static long connect(String url, String[] protocals, String caPath) {
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


        long connectionId = connectionIdGenerator.incrementAndGet();
        //TODO set timeout
        //TODO set self-signed CA
        Request request = builder.url(url).build();
        LocalWebSocketListener listener = new LocalWebSocketListener(connectionId);
        WebSocket socket = getClient().newWebSocket(request, listener);

        socketMap.put(connectionId, socket);
        return connectionId;
    }

    public static void disconnect(long connectionID) {
        WebSocket socket = socketMap.get(connectionID);
        if(socket != null) {
            socket.close(1000, "manually close by client");
        }else {
            Log.e("[WebSocket]", "socket "+connectionID + " not found!");
        }
    }

    public static void sendBinary(long connectionID, byte[] message)
    {
        WebSocket socket = socketMap.get(connectionID);
        if(socket != null) {
            socket.send(ByteString.of(message));
        }else {
            Log.e("[WebSocket]", "socket "+connectionID + " not found!");
        }
    }

    public static void sendString(long connectionID, String message)
    {
        WebSocket socket = socketMap.get(connectionID);
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
