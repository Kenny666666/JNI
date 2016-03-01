#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include "com_kenny_jni_c_c_MainActivity.h"  //引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

/**
 * 返回值char* 这个代表char数组的首地址
 * Jstring2CStr把java中的jstring的类型转化成一个C++语言中的char字符串
 */
char* Jstring2CStr(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = (env)->FindClass("java/lang/String");//找到java中的String 类
	jstring strencode = (env)->NewStringUTF("GB2312");	  //得到一个GB2312的字符串
	jmethodID mid = (env)->GetMethodID(clsstring, "getBytes",//得到String类中的getBytes方法，(Ljava/lang/String;) = 表示返回类型为String， [B = 表示参数为byte[]
			"(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(env)->CallObjectMethod(jstr, mid,
			strencode); // String .getByte("GB2312"); 调用String的getByte方法
	jsize alen = (env)->GetArrayLength(barr);
	jbyte* ba = (env)->GetByteArrayElements(barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1); //申请一个动态内存空间，alen+1 是为了给字符串最后一个置空"\0"
		memcpy(rtn, ba, alen);          //将ba拷贝到rtn中
		rtn[alen] = 0; 					//把rtn最后一个字符置空
	}
	(env)->ReleaseByteArrayElements(barr, ba, 0); //释放内存
	return rtn;
}

JNIEXPORT jstring JNICALL Java_com_kenny_jni_1c_1c_MainActivity_helloInC
  (JNIEnv * env, jobject obj)
{
	//C++代码跟C略有不同，无需用*了，直接用env，然后调用方法无需传env直接传字符串
	return (env)->NewStringUTF("haha from c");
	//其实C++这段代码做的工作如下，functions=*env
    //jstring NewStringUTF(const char* bytes)
    //{ return functions->NewStringUTF(this, bytes); }
}

JNIEXPORT jstring JNICALL Java_com_kenny_jni_1c_1c_MainActivity_helloInC__Ljava_lang_String_2
  (JNIEnv * env, jobject obj, jstring jstr)
{
	char* cstr = Jstring2CStr(env,jstr);
	LOGE("%s",cstr);
	return (env)->NewStringUTF("haha from c __");
}


















