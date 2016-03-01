package com.kenny.jni_c_c;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;

/**
 * 实际开发中C与C++的区别：Android.mk文件略有不同，方法调用略有不同（请看Hello.c与Hello.cpp）
 * @author kenny
 *
 */
public class MainActivity extends Activity {

	static{
		System.loadLibrary("Hello");
	}
	public native String helloInC();
	public native String helloInC(String str);//测试Hello.cpp中jstring2CStr是否生效(改成C++的了)
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        Button bt = (Button)findViewById(R.id.bt_1);
        bt.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Toast.makeText(getApplicationContext(), helloInC(), 0).show();
			}
		});
        Button bt2 = (Button)findViewById(R.id.bt_2);
        bt2.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				Toast.makeText(getApplicationContext(), helloInC(" java haha"), 0).show();
			}
		});
    }

}
