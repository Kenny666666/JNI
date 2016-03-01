#include<stdio.h>
#include<jni.h>
#include <malloc.h>
#include "com_demo_MainActivity.h"  //引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

//jni中java的String类型=jstring,函数的名字定义是有规则的:
//语言_项目包名_哪个activity要调_activity中的native方法名

//---------------------自己手写的方法名-------------------
//jstring Java_com_demo_MainActivity_helloFromC(JNIEnv* env ,jobject obj){
//
////	 return (*(*env)).NewStringUTF(env,"hello from c");
//	return (*env)->NewStringUTF(env,"hello from c");
//}

//如果函数有下划线必须在下划线前加1  如hello_1from_1c
//jstring Java_com_demo_MainActivity_hello_1from_1c(JNIEnv* env ,jobject obj){
//	return (*env)->NewStringUTF(env,"hello from c________");
//}

//-------------------使用javah命令生成的方法名--------------------
JNIEXPORT jstring JNICALL Java_com_demo_MainActivity_helloFromC(JNIEnv * env, jobject obj)
{
	  return (*env)->NewStringUTF(env,"hello from c");
}

JNIEXPORT jstring JNICALL Java_com_demo_MainActivity_hello_1from_1c(JNIEnv * env, jobject obj)
{
	LOGI("jni方法被调用");
		LOGE("初始化数组");
		//模拟常见错误(逻辑性错误)strcat此函数可以把一个字符串放在另一个字符串的后面，但有个要求：
		//a1的大小可以足够存放a2的值，所以程序调用这里会报错
		char a1[3] = {'a','b','c'};
		char a2[2] = {'e','f'};
		LOGE("数据初始化完毕");
		LOGE("开始拷贝数组");
		strcat(a1,a2);//把a2的内容放到a1后面
		LOGE("数组拷贝完毕");
		return (*env)->NewStringUTF(env,"hello from c________");
}

JNIEXPORT jstring JNICALL Java_com_demo_MainActivity_hello_1from_1c2(JNIEnv * env, jobject obj)
{
	LOGI("jni方法被调用");
	LOGE("初始化数组");
	char* a1 = (char*) malloc(sizeof(char)*10);
	*a1 = 'a';
	*(a1+1) = 'b';
	*(a1+9) = '\0';//\0代表字符串的结尾
	LOGE("a1 拷贝前 =%s",a1);
	char a2[2] = {'e','f'};
	LOGE("数据初始化完毕");
	LOGE("开始拷贝数组");
	strcat(a1,a2);//把a2的内容放到a1后面
	LOGE("a1 拷贝后 =%s",a1);
	LOGE("数组拷贝完毕");
	return (*env)->NewStringUTF(env,"hello from c________");
}

/**
 * 解决乱码问题
 */
JNIEXPORT jstring JNICALL Java_com_demo_MainActivity_hello_1from_1c3(JNIEnv * env, jobject obj)
{
	return (*env)->NewStringUTF(env,"你好啊乱码");//解决乱码：把.c文件编码格式设置为utf-8，不过ndk高版本不会出现乱码了
}
