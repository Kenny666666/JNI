package com.kenny.callback;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;

/**
 * c/c++代码回调java代码
 * @author kenny
 *
 */
public class MainActivity extends Activity implements OnClickListener {

	static{
		System.loadLibrary("Hello");
	}
	
	private Button bt_1;//c代码调用java中的空方法
	private Button bt_2;//c调用java中的带两个int参数的方法
	private Button bt_3;//c调用java中参数为strig的方法
	private Button bt_4;//c调用java中的静态方法
	private Button bt_5;//(类之间native方法相互调用)通过DataProvider2调用DataProvider中的method方法
	private DataProvider dataProvider;
	private DataProvider2 dataProvider2;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        dataProvider = new DataProvider();
        dataProvider2 = new DataProvider2();
        
        bt_1 = (Button)findViewById(R.id.bt_1);
        bt_2 = (Button)findViewById(R.id.bt_2);
        bt_3 = (Button)findViewById(R.id.bt_3);
        bt_4 = (Button)findViewById(R.id.bt_4);
        bt_5 = (Button)findViewById(R.id.bt_5);
        bt_1.setOnClickListener(this);
        bt_2.setOnClickListener(this);
        bt_3.setOnClickListener(this);
        bt_4.setOnClickListener(this);
        bt_5.setOnClickListener(this);
    }

	@Override
	public void onClick(View arg0) {
		switch (arg0.getId()) {
		case R.id.bt_1://c代码调用java中的空方法
			dataProvider.callmethod();
			break;
		case R.id.bt_2://c调用java中的带两个int参数的方法
			dataProvider.callmethod2();
			break;
		case R.id.bt_3://c调用java中参数为strig的方法
			dataProvider.callmethod3();
			break;
		case R.id.bt_4://c调用java中的静态方法
			dataProvider.callmethod4();
			break;
		case R.id.bt_5://通过DataProvider2调用DataProvider中的method方法
			dataProvider2.call_dataprovider_method();
			break;
		default:
			break;
		}
	}

}
