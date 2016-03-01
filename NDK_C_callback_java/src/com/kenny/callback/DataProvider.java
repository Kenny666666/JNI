package com.kenny.callback;

import android.util.Log;

public class DataProvider {
	private final static String TAG ="DataProvider";
	/**c调用java中的空方法*/
	public void helloFromJava(){
		Log.e(TAG,"hello from java");
	}
	/**c调用java中的带两个int参数的方法*/
	public int add(int x ,int y){
		int result = x+y;
		Log.e(TAG,"java result=" + result);
		return x+y;
	}
	/**c调用java中参数为strig的方法*/
	public void printString(String s){
		Log.e(TAG,"java="+s);
	}
	public static void printStaticStr(String s){
		Log.e(TAG,"java static :"+s);
	}
	
	//让c代码调用对应的java代码
	public native void callmethod();
	public native void callmethod2();
	public native void callmethod3();
	//调用一个静态的方法
	public native void callmethod4();
}
