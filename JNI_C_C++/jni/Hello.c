#include<stdio.h>
#include "com_kenny_jni_c_c_MainActivity.h"  //引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);


JNIEXPORT jstring JNICALL Java_com_kenny_jni_1c_1c_MainActivity_helloInC
  (JNIEnv * env, jobject obj)
{
	return (*env)->NewStringUTF(env,"haha from c");
}
