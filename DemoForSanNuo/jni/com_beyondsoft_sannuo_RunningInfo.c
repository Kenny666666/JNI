#include "com_beyondsoft_sannuo_RunningInfo.h"
#include "car_internal_show_R.h"

extern int StartRunning(void);
extern car_show_iterm_t tojava_1;

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    StartRunning
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_beyondsoft_sannuo_RunningInfo_StartRunning
  (JNIEnv * env, jobject jobj)
{
	StartRunning();
  	return 0;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    StopRuning
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_com_beyondsoft_sannuo_RunningInfo_StopRuning
  (JNIEnv * env, jobject jobj)
{
	return 0;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetWelcomInfo
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetWelcomInfo
  (JNIEnv * env, jobject obj)
{
	return (*env)->NewStringUTF(env, "Welcom Sannuo");
}
/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetRotateSpeed
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetRotateSpeed
  (JNIEnv * env, jobject obj)
{
	return (jshort)(tojava_1.speed1);
}
/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetVehicleSpeed
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetVehicleSpeed
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed2;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetWaterTemperature
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetWaterTemperature
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed3;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetAirDamper
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetAirDamper
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed4;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetTirePressure
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetTirePressure
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed5;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetOilMass
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetOilMass
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed6;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetOilWear
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetOilWear
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed7;
}

/*
 * Class:     com_beyondsoft_sannuo_RunningInfo
 * Method:    GetRemainingOil
 * Signature: ()S
 */
JNIEXPORT jshort JNICALL Java_com_beyondsoft_sannuo_RunningInfo_GetRemainingOil
  (JNIEnv * env, jobject obj)
{
	return (jshort)tojava_1.speed8;
}
