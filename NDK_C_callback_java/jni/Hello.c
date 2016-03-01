#include<stdio.h>
#include<jni.h>
#include <malloc.h>
#include "com_kenny_callback_DataProvider.h"  //引入本地.h文件
#include "com_kenny_callback_DataProvider2.h"  //引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

JNIEXPORT void JNICALL Java_com_kenny_callback_DataProvider_callmethod
  (JNIEnv * env, jobject obj)
{
	//在c代码里面调用java代码里面的方法
	//利用java反射技术
	//1、找到java代码的class文件,jni给我们提供了一个方法
	// jclass = (*FindClass)(JNIEnv*,const char*);
	jclass dataprovider = (*env)->FindClass(env,"com/kenny/callback/DataProvider");
	if(dataprovider == 0)
	{
		LOGE("没有找到类DataProvider");
		return;
	}
	LOGE("找到类");
	//2、寻找class里面的方法
	//JNIEnv*=env，jclass=dataprovider，char*=helloFromJava（java代码中的方法名），char*=java代码中的方法的参数()表示0参数，V表示无返回值
	// jmethodID = (*GetMethodID)(JNIEnv*,jclass,const char*,const char*)
	jmethodID method = (*env)->GetMethodID(env,dataprovider,"helloFromJava","()V");
	if(method == 0)
		{
			LOGE("没有找到方法");
			return;
		}
	LOGE("找到方法");
	//3、调用这个方法
	//void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,method);
}

JNIEXPORT void JNICALL Java_com_kenny_callback_DataProvider_callmethod2
  (JNIEnv * env, jobject obj)
{
	//在c代码里面调用java代码里面的方法
	//利用java反射技术
	//1、找到java代码的class文件,jni给我们提供了一个方法
	// jclass = (*FindClass)(JNIEnv*,const char*);
	jclass dataprovider = (*env)->FindClass(env,"com/kenny/callback/DataProvider");
	if(dataprovider == 0)
	{
		LOGE("没有找到类DataProvider");
		return;
	}
	LOGE("找到类");
	//2、寻找class里面的方法
	//JNIEnv*=env，jclass=dataprovider，char*=add（java代码中的方法名），char*=java代码中的方法的参数(II)表示2个int参数，I表示int类型的返回值
	// jmethodID = (*GetMethodID)(JNIEnv*,jclass,const char*,const char*)
	jmethodID method2 = (*env)->GetMethodID(env,dataprovider,"add","(II)I");
	if(method2 == 0)
		{
			LOGE("没有找到方法");
			return;
		}
	LOGE("找到方法");
	//3、调用这个方法
	//int   (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
	int result = (*env)->CallIntMethod(env, obj, method2 , 3, 5);
	LOGE("C result = %d",result);
}

JNIEXPORT void JNICALL Java_com_kenny_callback_DataProvider_callmethod3
  (JNIEnv * env, jobject obj)
{
	//在c代码里面调用java代码里面的方法
	//利用java反射技术
	//1、找到java代码的class文件,jni给我们提供了一个方法
	// jclass = (*FindClass)(JNIEnv*,const char*);
	jclass dataprovider = (*env)->FindClass(env,"com/kenny/callback/DataProvider");
	if(dataprovider == 0)
	{
		LOGE("没有找到类DataProvider");
		return;
	}
	LOGE("找到类");
	//2、寻找class里面的方法
	//JNIEnv*=env，jclass=dataprovider，char*=printString（java代码中的方法名），char*=java代码中的方法的参数(Ljava/lang/String;)表示String参数，V表示无返回值
	// jmethodID = (*GetMethodID)(JNIEnv*,jclass,const char*,const char*)
	jmethodID method3 = (*env)->GetMethodID(env,dataprovider,"printString","(Ljava/lang/String;)V");
	if(method3 == 0)
		{
			LOGE("没有找到方法");
			return;
		}
	LOGE("找到方法");
	//3、调用这个方法
	//   (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env, obj, method3 , (*env)->NewStringUTF(env,"haha in c"));
}

JNIEXPORT void JNICALL Java_com_kenny_callback_DataProvider_callmethod4
  (JNIEnv * env, jobject obj)
{
	//在c代码里面调用java代码里面的方法
	//利用java反射技术
	//1、找到java代码的class文件,jni给我们提供了一个方法
	// jclass = (*FindClass)(JNIEnv*,const char*);
	jclass dataprovider = (*env)->FindClass(env,"com/kenny/callback/DataProvider");
	if(dataprovider == 0)
	{
		LOGE("没有找到类DataProvider");
		return;
	}
	LOGE("找到类");
	//2、寻找class里面的方法，
	//注意：如果要寻找的方法是静态的方法那就不能通过GetMethodID去获取,要使用GetStaticMethodID
	//JNIEnv*=env，jclass=dataprovider，char*=printStaticStr（java代码中的方法名），char*=java代码中的方法的参数(Ljava/lang/String;)表示String参数，V表示无返回值
	// jmethodID = (*GetStaticMethodID)(JNIEnv*,jclass,const char*,const char*)
	jmethodID method4 = (*env)->GetStaticMethodID(env,dataprovider,"printStaticStr","(Ljava/lang/String;)V");
	if(method4 == 0)
		{
			LOGE("没有找到方法");
			return;
		}
	LOGE("找到方法");
	//3、调用一个静态的java方法
	//   (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
	(*env)->CallStaticVoidMethod(env, dataprovider, method4 , (*env)->NewStringUTF(env,"static haha in c"));
}

/**调用DataProvider类中的callmethod方法*/
//obj = DataProvider2
JNIEXPORT void JNICALL Java_com_kenny_callback_DataProvider2_call_1dataprovider_1method
  (JNIEnv * env, jobject obj)
{
	//在c代码里面调用java代码里面的方法
	//利用java反射技术
	//1、找到java代码的class文件,jni给我们提供了一个方法
	// jclass = (*FindClass)(JNIEnv*,const char*);
	jclass dataprovider = (*env)->FindClass(env,"com/kenny/callback/DataProvider");
	if(dataprovider == 0)
	{
		LOGE("没有找到类DataProvider");
		return;
	}
	LOGE("找到类");
	//2、寻找class里面的方法
	//JNIEnv*=env，jclass=dataprovider，char*=helloFromJava（java代码中的方法名），char*=java代码中的方法的参数()表示0参数，V表示无返回值
	// jmethodID = (*GetMethodID)(JNIEnv*,jclass,const char*,const char*)
	jmethodID method = (*env)->GetMethodID(env,dataprovider,"helloFromJava","()V");
	if(method == 0)
		{
			LOGE("没有找到方法");
			return;
		}
	LOGE("找到方法");
	//3、调用这个方法
	//    jobject     (*AllocObject)(JNIEnv*, jclass);  || jobject     (*NewObject)(JNIEnv*, jclass, jmethodID, ...);
	jobject dpobj = (*env)->AllocObject(env,dataprovider);
	(*env)->CallVoidMethod(env,dpobj,method);
}
