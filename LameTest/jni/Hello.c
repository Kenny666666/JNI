#include<stdio.h>
#include <malloc.h>
#include<lame.h>
#include "com_kenny_lame_MainActivity.h"  //引入本地.h文件
//在c代码中打印log
#include <android/log.h>
#define LOG_TAG "System.out.c"
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, __VA_ARGS__);
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__);
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__);

int flag = 0;//中止线程的标识
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

void publishJavaProgress(JNIEnv * env, jobject obj, jint progress){
	//调用java代码更新程序的进度条
	//1、找到java的MainActivity
	jclass clazz = (*env)->FindClass(env,"com/kenny/lame/MainActivity");
	if(clazz == 0){
		LOGE("can't find class");
	}
	LOGE("find class");
	//2、寻找class里面的方法
	//JNIEnv*=env，jclass=clazz，char*=setConvertProgress（java代码中的方法名），char*=java代码中的方法的参数(I)表示int参数，V表示无返回值
	// jmethodID = (*GetMethodID)(JNIEnv*,jclass,const char*,const char*)
	jmethodID method = (*env)->GetMethodID(env,clazz,"setConvertProgress","(I)V");
	if(method == 0)
		{
			LOGE("没有找到方法");
			return;
		}
	LOGE("找到方法");
	//3、调用这个方法
	//void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
	(*env)->CallVoidMethod(env,obj,method,progress);
}

/**
 * 将wav格式文件转化成mp3格式
 */
JNIEXPORT void JNICALL Java_com_kenny_lame_MainActivity_convertmp3
  (JNIEnv * env, jobject obj, jstring jwav, jstring jmp3)
{
	char* cwav = Jstring2CStr(env,jwav);
	char* cmp3 = Jstring2CStr(env,jmp3);
	LOGE("wav = %s", cwav);
	LOGE("mp3 = %s", cmp3);

	//1、打开wav,mp3文件
	FILE* fwav = fopen(cwav,"rb");//rb以二进制方式读出来
	FILE* fmp3 = fopen(cmp3,"wb");//wb以二进制方式写入

	short int wav_buffer[8192 * 2];//8192是随便设置的如果手机性能比较牛，可以多设置点
	unsigned char mp3_buffer[8192];

	//1、初始化lame的编码器
	lame_t lame = lame_init();
	//2、设置lame  mp3编码的采样率
	lame_set_in_samplerate(lame,44100);
	//设置声道数,默认2个
	lame_set_num_channels(lame,2);
	//3、设置mp3的编码方式(压缩算法)，请看E:\Android\Androidvideo\JNI\jni_day03\资料\音频格式.doc
	lame_set_VBR(lame,vbr_default);
	//初始化参数完成
	lame_init_params(lame);
	LOGE("lame init finish");

	int read; //代表读了多少次
	int write;//写了多少次
	int total = 0;
	do
	{
		if(flag == 404){//用户中止了线程
			return;
		}
		read = fread(wav_buffer,sizeof(short int) * 2, 8192, fwav);
		total += read * sizeof(short int) * 2;
		LOGE("converting...%d",total);
		//调用java代码完成进度条的更新
		publishJavaProgress(env,obj,total);

		if(read != 0)
		{
			//参数一：lame编码器
			//参数二：要转化的原始的数据
			//参数三：要读多少次
			//参数四：转化后的内容放的位置
			//参数五：转化后的缓冲区mp3_buffer大小
			write = lame_encode_buffer_interleaved(lame,wav_buffer,read,mp3_buffer,8192);
			//把转化后的mp3数据写到文件里
			fwrite(mp3_buffer,sizeof(unsigned char),write,fmp3);
		}
		//读到了文件的末尾
		if (read == 0) {
			lame_encode_flush(lame,mp3_buffer,8192);
		}
	}while(read != 0);
	LOGE("convert finish");

	//返初始化编码器操作
	lame_close(lame);
	fclose(fwav);
	fclose(fmp3);
}

/**
 * 获取lame版本号
 */
JNIEXPORT jstring JNICALL Java_com_kenny_lame_MainActivity_getLameVersion
  (JNIEnv * env, jobject obj)
{
	return (*env)->NewStringUTF(env,get_lame_version());
}
