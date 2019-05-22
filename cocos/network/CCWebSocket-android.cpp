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

namespace {
    void _nativeTriggerEvent(JNIEnv *env, jclass *klass, jlong cid, jstring eventName, jstring data) {

    }

    int64_t callJavaSendBinary(int64_t cid, const char *data, size_t len) {

        JniMethodInfo methodInfo;
        if (JniHelper::getStaticMethodInfo(methodInfo,
                                           J_BINARY_CLS_WEBSOCKET,
                                           "sendBinary",
                                           "(J"  JARG_STR JARG_STR")V")) {
            jlong connectionID = cid;
            jstring jstrURL = methodInfo.env->New
            //jstring jstrPath = methodInfo.env->NewStringUTF(task->storagePath.c_str());
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, connectionID, nullptr);
            methodInfo.env->DeleteLocalRef(jstrURL);
            //methodInfo.env->DeleteLocalRef(jstrPath);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }

    }
    /*
    int64_t callJavaSendString(int64_t cid, const std::string &data) {
        JniMethodInfo methodInfo;
        if (JniHelper::getStaticMethodInfo(methodInfo,
                                           J_BINARY_CLS_WEBSOCKET,
                                           "sendString",
                                           "(J[B)V")) {
            jstring jstrURL = methodInfo.env->NewStringUTF(task->requestURL.c_str());
            jstring jstrPath = methodInfo.env->NewStringUTF(task->storagePath.c_str());
            methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID, _impl,
                                                 coTask->id, jstrURL, jstrPath);
            methodInfo.env->DeleteLocalRef(jstrURL);
            methodInfo.env->DeleteLocalRef(jstrPath);
            methodInfo.env->DeleteLocalRef(methodInfo.classID);
        }

    }
     */
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
