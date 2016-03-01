#include<stdio.h>
#include<jni.h>
#include<stdlib.h>
#include "com_kenny_monitor_MainActivity.h"  //引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

/**获取压力的方法*/
int getpressure(){
	//c语言中的随机数
	return rand();
}


JNIEXPORT jint JNICALL Java_com_kenny_monitor_MainActivity_getPressure
  (JNIEnv * env, jobject obj)
{
	return getpressure();
}
