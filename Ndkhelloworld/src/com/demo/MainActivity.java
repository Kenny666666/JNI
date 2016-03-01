package com.demo;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;
/**
 * jni使用步骤
 * 1、创建android工程
 * 2、创建jni文件夹
 * 3、在activity中创建native方法  如：public native String hellFromC();
 * 4、在jni文件夹中创建.c文件，编写c代码
 * 5、创建Android.mk文件并配置好相关位置 如:LOCAL_MODULE    := Hello    //编译后的名字
   								  LOCAL_SRC_FILES := Hello.c  //要编译的.c文件
 * 6、使用Cygwin定位到项目文件位置Ndkhelloworld，使用命令ndk-build就会自动编译Hello.c文件
 * 之后会在libs中生成armeabi/libHello.so 文件(可执行的二进制文件)
 * 7、在activity中加载libHello.so文件
 * static{
		//加载的文件为编译后的文件名（LOCAL_MODULE） = Hello，让java虚拟机能够运行libHello.so文件
		System.loadLibrary("Hello");
	}
 * 8、在按钮事件中调用Toast.makeText(MainActivity.this, helloFromC(), Toast.LENGTH_SHORT).show();
 * 9、ndk-build常用技巧：在重新编写c文件后，使用ndk-build命令时最好先ndk-build clear  清一下缓存
 */
public class MainActivity extends Activity {
	private Button button;
	private Button button2;
	private Button button3;
	private Button button4;
	
	static{
		System.loadLibrary("Hello");
	}
	//申明一个本地方法
	public native String helloFromC();
	//出现下划线的方法名编译方法看Hello.c文件       //如果函数有下划线必须在下划线前加1  如hello_1from_1c
	//像出现这种复杂的函数名时我们可以借助cmd-javah命令来给我们生成对应方法名，这样就不会范错了
	//方法：1、把.java文件用javac命令先生成.class文件(javac HelloWorld.java)
	//    2、然后使用javah生成.h文件，打开.h文件找到对应方法名拷贝使用(javah HelloWorld)
	
	//注意：在.java文件中如果存在package com.demo;这样的包名，在使用.javah的时候要显示的指定
	//方法：A、dos命令先定位到MainActivity.java目录，如cd /d E:\Android\AndroidFile\JNI\Ndkhelloworld\src\com\demo
	//                                             cmd -->  e:  -->  cd E:\Android\AndroidFile\JNI\Ndkhelloworld\src\com\demo
	
	//	  B、然后cd .. 回到src文件位置
	//    C、使用javah com.demo.HelloWorld 就可以生成.h文件了
	//    D、把生成的.h文件拷贝到jni文件夹下
	//    E、打开生成的.h文件把方法拷贝出来，放Hell.c中
	public native String hello_from_c();
	
	public native String hello_from_c2();
	/**解决c中的乱码问题*/
	public native String hello_from_c3();
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		
		button = (Button) this.findViewById(R.id.button);
		button2 = (Button) this.findViewById(R.id.button2);
		button3 = (Button) this.findViewById(R.id.button3);
		button4 = (Button) this.findViewById(R.id.button4);
		button.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Toast.makeText(MainActivity.this, helloFromC(), Toast.LENGTH_SHORT).show();
			}
		});
		button2.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Toast.makeText(MainActivity.this, hello_from_c(), Toast.LENGTH_SHORT).show();
			}
		});
		button3.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Toast.makeText(MainActivity.this, hello_from_c2(), Toast.LENGTH_SHORT).show();
			}
		});
		button4.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Toast.makeText(MainActivity.this, hello_from_c3(), Toast.LENGTH_SHORT).show();
			}
		});
	}
}
