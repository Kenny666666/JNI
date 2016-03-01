#include <stdio.h>
#include <jni.h>
#include <malloc.h>
#include "com_kenny_jnilogin_MainActivity.h";//引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

/**
 * 返回值char* 这个代表char数组的首地址
 * Jstring2CStr把java中的jstring的类型转化成一个c语言中的char字符串
 */
char* Jstring2CStr(JNIEnv* env, jstring jstr) {
	char* rtn = NULL;
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");
	jstring strencode = (*env)->NewStringUTF(env, "GB2312");
	jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",
			"(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
			strencode); // String .getByte("GB2312");
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1); //"\0"
		memcpy(rtn, ba, alen);
		rtn[alen] = 0;
	}
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0); //
	return rtn;
}

//登录的方法(模拟)   成功200 失败400
int login(char* username,char* pwd)
{
    //连接网络发送数据给服务器
    char* rightname = "zhangsan";
    char* rightpwd = "123";
    int i = 0;
    for(;username[i] != '\0'; i++)
    {
       if(username[i] != rightname[i])
         return 404;
    }
    return 200;
}

JNIEXPORT jint JNICALL Java_com_kenny_jnilogin_MainActivity_call_1login
  (JNIEnv* env, jobject obj, jstring jname, jstring jpwd){
	char* cname = Jstring2CStr(env,jname);
	char* cpwd = Jstring2CStr(env,jpwd);
	LOGE("name = %s",cname);
	LOGE("pwd = %s",cpwd);
	return login(cname,cpwd);
}
