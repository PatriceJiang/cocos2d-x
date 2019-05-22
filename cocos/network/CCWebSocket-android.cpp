//
// Created by jiang on 19-5-22.
//

#include "network/CCWebSocket-android.h"

#include "network/WebSocket.h"
#include "platform/android/jni/JniHelper.h"


#define JCLS_WEBSOCKET "org/cocos2dx/lib/Cocos2dxWebSocket"
#define J_BINARY_CLS_WEBSOCKET "org.cocos2dx.lib.Cocos2dxWebSocket"
#define JARG_STR        "Ljava/lang/String;"
#define JARG_DOWNLOADER "L" JCLS_WEBSOCKET ";"
#define JARG_TASK       "L" JCLS_TASK ";"

#include <string>
#include <mutex>
using namespace std;

static bool _registerNativeMethods(JNIEnv* env);

namespace cocos2d {
    bool registered = false;
    namespace network {
        void _preloadJavaWebSocketClass(JNIEnv* env)
        {
            if(!registered)
            {
                registered = _registerNativeMethods(env);
            }
        }
    }
}

namespace cocos2d{
    void _nativeTriggerEvent(JNIEnv *env, jclass *klass, jlong cid, jstring eventName, jstring data) {

    }

    int64_t _callJavaConnect(const std::string &url,const std::vector<std::string> &protocals, const std::string & caFile)
    {
        jlong connectionID = -1;
        JniMethodInfo methodInfo;
        if (JniHelper::getStaticMethodInfo(methodInfo,
                                           J_BINARY_CLS_WEBSOCKET,
                                           "connect",
                                           "(" JARG_STR "[" JARG_STR JARG_STR")J")) {
            jstring jurl = methodInfo.env->NewStringUTF(url.c_str());
            jstring jcaFile = methodInfo.env->NewStringUTF(caFile.c_str());

            jclass stringClass = methodInfo.env->FindClass("java/lang/String");

            jobjectArray jprotocals = methodInfo.env->NewObjectArray((jsize)protocals.size(), stringClass, methodInfo.env->NewStringUTF(""));
            for(int i=0;i<protocals.size(); i++)
            {
                jstring item = methodInfo.env->NewStringUTF(protocals[i].c_str());
                methodInfo.env->SetObjectArrayElement(jprotocals, i, item);
            }

            connectionID = methodInfo.env->CallStaticLongMethod(methodInfo.classID, methodInfo.methodID, jurl, jprotocals, jcaFile);
            methodInfo.env->DeleteLocalRef(jurl);
            methodInfo.env->DeleteLocalRef(jcaFile);
            methodInfo.env->DeleteLocalRef(stringClass);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }

        return connectionID;
    }

    void _callJavaDisconnect(int64_t cid)
    {
        jlong connectionID = -1;
        JniMethodInfo methodInfo;
        if (JniHelper::getStaticMethodInfo(methodInfo,
                                           J_BINARY_CLS_WEBSOCKET,
                                           "disconnect",
                                           "(J)V")) {
            jlong connectionID = cid;
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, connectionID);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }

    }


    void _callJavaSendBinary(int64_t cid, const char *data, size_t len)
    {

        JniMethodInfo methodInfo;
        if (JniHelper::getStaticMethodInfo(methodInfo,
                                           J_BINARY_CLS_WEBSOCKET,
                                           "sendBinary",
                                           "(J"  JARG_STR JARG_STR")V")) {
            jlong connectionID = cid;
            jbyteArray jdata = methodInfo.env->NewByteArray((jsize)len);
            methodInfo.env->SetByteArrayRegion(jdata, 0, (jsize)len, (const jbyte *)data);
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, connectionID, jdata);
            methodInfo.env->DeleteLocalRef(jdata);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }

    }

    void _callJavaSendString(int64_t cid, const std::string &data) {
        JniMethodInfo methodInfo;
        if (JniHelper::getStaticMethodInfo(methodInfo,
                                           J_BINARY_CLS_WEBSOCKET,
                                           "sendString",
                                           "(J"  JARG_STR JARG_STR")V")) {
            jlong connectionID = cid;
            jstring jdata = methodInfo.env->NewStringUTF(data.c_str());
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, connectionID, jdata);
            methodInfo.env->DeleteLocalRef(jdata);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }
    }

    static JNINativeMethod sMethodTable[] = {
            { "triggerEvent", "(J"JARG_STR JARG_STR ")V", (void*)_nativeTriggerEvent},
            //{ "nativeOnFinish", "(III" JARG_STR "[B)V", (void*)_nativeOnFinish },
    };

    static bool _registerNativeMethods(JNIEnv* env)
    {
        jclass clazz = env->FindClass(JCLS_WEBSOCKET);
        if (clazz == NULL)
        {
            CCLOG("_registerNativeMethods: can't find java class:%s", JARG_DOWNLOADER);
            return false;
        }
        if (JNI_OK != env->RegisterNatives(clazz, sMethodTable, sizeof(sMethodTable) / sizeof(sMethodTable[0])))
        {
            //DLLOG("_registerNativeMethods: failed");
            if (env->ExceptionCheck())
            {
                env->ExceptionClear();
            }
            return false;
        }
        return true;
    }
}

