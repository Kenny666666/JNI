package com.kenny.jnilogin;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

/**
 * 实际开发中JNI使用案例
 * @author kenny
 *
 */
public class MainActivity extends Activity {

	private Button btLogin;
	private EditText etName,etPwd;
	
	static{
		System.loadLibrary("Hello");
	}
	public native int call_login(String name,String pwd);
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        etName = (EditText) findViewById(R.id.et_username);
        etPwd = (EditText) findViewById(R.id.et_pwd);
        btLogin = (Button) findViewById(R.id.bt_login);
        btLogin.setOnClickListener(new OnClickListener() {
			
			@Override
			public void onClick(View arg0) {
				String name = etName.getText().toString();
				String pwd = etPwd.getText().toString();
				
				int result = call_login(name, pwd);
				if (result ==200) {
					Toast.makeText(getApplicationContext(), "登录成功", 0).show();
				}else {
					Toast.makeText(getApplicationContext(), "登录失败" + result, 0).show();
				}
			}
		});
    }
}
