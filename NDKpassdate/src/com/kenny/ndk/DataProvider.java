package com.kenny.ndk;

import android.R.integer;

/**
 * java传递数据给c语言
 * @author kenny
 *
 */
public class DataProvider {
	
	//生成.h文件的方法：1、把.java文件用javac命令先生成.class文件(javac HelloWorld.java)
	//    2、然后使用javah生成.h文件，打开.h文件找到对应方法名拷贝使用(javah HelloWorld)
	
	//注意：在.java文件中如果存在package com.demo;这样的包名，在使用.javah的时候要显示的指定
	//方法：A、dos命令先定位到MainActivity.java目录，如cd /d E:\Android\AndroidFile\JNI\Ndkhelloworld\src\com\demo
	//                                             cmd -->  e:  -->  cd E:\Android\AndroidFile\JNI\Ndkhelloworld\src\com\demo
	//	  B、然后cd .. 回到src文件位置
	//    C、使用javah com.demo.HelloWorld 就可以生成.h文件了
	//    D、把生成的.h文件拷贝到jni文件夹下
	//    E、打开生成的.h文件把方法拷贝出来，放Hell.c中
	
	/**
	 * 把两个java中的int传递给c语言，c语言处理完毕后把结果返回给java
	 * @param x 
	 * @param y
	 * @return
	 */
	public native int add(int x,int y);
	
	/**
	 * 把java中的string传递给c语言，c语言获取到java中的string后，在string后面添加hello字符串
	 * @param s
	 * @return
	 */
	public native String sayHelloInC(String s);
	
	/**
	 * 把java中的Int数组传递给c语言，c语言处理完毕这个java数组
	 * 把Int数组中的每一个元素+10
	 * 然后把结果返回给Java
	 * @param iNum
	 * @return
	 */
	public native int[] intMethod(int[] iNum);
	
	/**
	 * 静态方法申明
	 * @param x
	 * @param y
	 * @return
	 */
	public static native int sub(int x,int y);
}
