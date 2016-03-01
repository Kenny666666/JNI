#include <stdio.h>
#include <jni.h>
#include <malloc.h>
#include "com_kenny_ndk_DataProvider.h";//引入本地.h文件
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
	jclass clsstring = (*env)->FindClass(env, "java/lang/String");//找到java中的String 类
	jstring strencode = (*env)->NewStringUTF(env, "GB2312");	  //得到一个GB2312的字符串
	jmethodID mid = (*env)->GetMethodID(env, clsstring, "getBytes",//得到String类中的getBytes方法，(Ljava/lang/String;) = 表示返回类型为String， [B = 表示参数为byte[]
			"(Ljava/lang/String;)[B");
	jbyteArray barr = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid,
			strencode); // String .getByte("GB2312"); 调用String的getByte方法
	jsize alen = (*env)->GetArrayLength(env, barr);
	jbyte* ba = (*env)->GetByteArrayElements(env, barr, JNI_FALSE);
	if (alen > 0) {
		rtn = (char*) malloc(alen + 1); //申请一个动态内存空间，alen+1 是为了给字符串最后一个置空"\0"
		memcpy(rtn, ba, alen);          //将ba拷贝到rtn中
		rtn[alen] = 0; 					//把rtn最后一个字符置空
	}
	(*env)->ReleaseByteArrayElements(env, barr, ba, 0); //释放内存
	return rtn;
}

/**
 * 解决中文乱码问题
 */
jstring C2Jstring(JNIEnv *env, char* tmpstr) {
	jclass Class_string;
	jmethodID mid_String, mid_getBytes;
	jbyteArray bytes;
	jbyte* log_utf8;
	jstring codetype, jstr;
	Class_string = (*env)->FindClass(env, "java/lang/String"); //获取class
	//先将gbk字符串转为java里的string格式
	mid_String = (*env)->GetMethodID(env, Class_string, "<init>","([BLjava/lang/String;)V");
	bytes = (*env)->NewByteArray(env, strlen(tmpstr));
	(*env)->SetByteArrayRegion(env, bytes, 0, strlen(tmpstr), (jbyte*) tmpstr);
	codetype = (*env)->NewStringUTF(env, "gbk");
	jstr = (jstring)(*env)->NewObject(env, Class_string, mid_String, bytes,
			codetype);

	(*env)->DeleteLocalRef(env, bytes);

	//再将string变utf-8字符串。
	mid_getBytes = (*env)->GetMethodID(env, Class_string, "getBytes","(Ljava/lang/String;)[B");
	codetype = (*env)->NewStringUTF(env, "utf-8");
	bytes = (jbyteArray)(*env)->CallObjectMethod(env, jstr, mid_getBytes,codetype);
	log_utf8 = (*env)->GetByteArrayElements(env, bytes, JNI_FALSE);
	LOGI(log_utf8);
	return (*env)->NewStringUTF(env, log_utf8);
}

/**
 * 非静态方法
 * *env = java虚拟机结构体(c实现的指针)包含有很多jni方法
 * jobject obj代表的是调用这个c代码的java对象 = 实例化出来DataProvider的对象
 */
JNIEXPORT jint JNICALL Java_com_kenny_ndk_DataProvider_add(JNIEnv* env,
		jobject obj, jint x, jint y) {
	LOGE("x=%d", x);
	LOGE("y=%d", y);
	return x + y;
}

JNIEXPORT jstring JNICALL Java_com_kenny_ndk_DataProvider_sayHelloInC
  (JNIEnv * env, jobject obj, jstring jstr ){
	//在c语言中 是没有java的String
	char* cstr = Jstring2CStr(env, jstr);
	LOGD("cstr=%s",cstr);
	// c语言中的字符串 都是以'\0' 作为结尾，否则系统会给字符串最后乱加字符
	char arr[7]= {' ','h','e','l','l','o','\0'};
	strcat(cstr,arr);
	LOGD("new cstr=%s",cstr);
	return (*env)->NewStringUTF(env,cstr);
}

JNIEXPORT jintArray JNICALL Java_com_kenny_ndk_DataProvider_intMethod(
		JNIEnv* env, jobject obj, jintArray arr) {
	//处理一个数组分两步
	//1.知道数组的长度
	//2.操作这个数组里面的每一个元素

	//得到数组长度
	int len = (*env)->GetArrayLength(env, arr);
	LOGE("数组的长度=%d", len);
	//将jintArray数组转换成jint*指针(其它数据类型对应)
	jint* intarr = (*env)->GetIntArrayElements(env, arr, 0);
	int i = 0;
	for (; i < len; i++) {

		LOGE("intarr[%d] = %d", i, intarr[i]);
		//将数组的每一个元素都+10
		*(intarr + i) += 10; //或者intarr[i] += 10;
	}
	//释放掉刚才申请的内存空间，养成良好习惯（这里有问题要想办法解决掉）
	//(*env)->ReleaseIntArrayElements(env,arr,intarr,len);
	return arr;
}

/**
 * 静态方法
 * *env = java虚拟机结构体(c实现的指针)包含有很多jni方法
 * clazz代表的是调用c代码的class（类）
 * 这里jclass = DataProvider
 */
JNIEXPORT jint JNICALL Java_com_kenny_ndk_DataProvider_sub(JNIEnv * env, jclass clazz, jint x, jint y)
{
	LOGE("x=%d", x);
	LOGE("y=%d", y);
	return x-y;
}

