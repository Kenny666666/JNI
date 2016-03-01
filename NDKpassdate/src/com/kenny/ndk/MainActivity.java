package com.kenny.ndk;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.Toast;


public class MainActivity extends Activity implements OnClickListener {

	private Button bt1;
	private Button bt2;
	private Button bt3;
	private Button bt4;
	
	DataProvider provider;
	
	static{
		System.loadLibrary("Hello");
	}
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        bt1 = (Button) this.findViewById(R.id.bt_1);
        bt2 = (Button) this.findViewById(R.id.bt_2);
        bt3 = (Button) this.findViewById(R.id.bt_3);
        bt4 = (Button) this.findViewById(R.id.bt_4);
        bt1.setOnClickListener(this);
        bt2.setOnClickListener(this);
        bt3.setOnClickListener(this);
        bt4.setOnClickListener(this);
        
        provider = new DataProvider();
    }

	@Override
	public void onClick(View arg0) {
		switch (arg0.getId()) {
		case R.id.bt_1:
			int result = provider.add(3, 5);
			Toast.makeText(this, "相加的结果" + result, 0).show();
			break;
		case R.id.bt_2:
			String str = provider.sayHelloInC("huguoshan");//传中文会挂，.c文件中有解决中文乱码的函数
			Toast.makeText(this, "" + str, 0).show();
			break;
		case R.id.bt_3:
			int arr[] = {1,2,3,4,5};
			provider.intMethod(arr);
			for (int i = 0; i < arr.length; i++) {
				Log.e("MainActivity:","java " + arr[i] + "\n");
			}
			break;
		case R.id.bt_4:
			int subResult = DataProvider.sub(5, 3);
			Toast.makeText(this, "相减的结果：" + subResult, 0).show();
			break;
		default:
			break;
		}
	}



}
