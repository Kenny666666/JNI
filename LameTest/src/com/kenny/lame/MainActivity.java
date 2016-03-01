package com.kenny.lame;

import java.io.File;

import android.app.Activity;
import android.app.ProgressDialog;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

/**
 * 使用C开源框架lame给wav音频文件进行mp3编码
 * @author kenny
 *
 */
public class MainActivity extends Activity implements OnClickListener {

	private EditText etWav;
	private EditText etMp3;
	private Button btChange;
	private Button btGetVersion;
	private Button btSearchFile;
	private ProgressDialog pd;
	
	static{
		System.loadLibrary("Hello");
	}
	/**转化成mp3*/
	public native void convertmp3(String wav,String mp3);
	/**获取lame版本号*/
	public native String getLameVersion();
	/**中止转化线程，没完成*/
	public native void stop();
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        etWav = (EditText) findViewById(R.id.et_source_file_path);
        etMp3 = (EditText) findViewById(R.id.et_target_file_path);
        btChange = (Button) findViewById(R.id.bt_change);
        btChange.setOnClickListener(this);
        btGetVersion = (Button) findViewById(R.id.bt_get_version);
        btGetVersion.setOnClickListener(this);
        btSearchFile = (Button) findViewById(R.id.bt_search_file);
        btSearchFile.setOnClickListener(this);
        pd = new ProgressDialog(this);
    }

	@Override
	public void onClick(View arg0) {
		switch (arg0.getId()) {
		case R.id.bt_search_file://搜索文件
			String wav = Environment.getExternalStorageDirectory().getAbsoluteFile() + "/lamemp3/ylzs.wav";
			String mp3 = Environment.getExternalStorageDirectory().getAbsoluteFile() + "/lamemp3/ylzs.mp3";
			etWav.setText(wav);
			etMp3.setText(mp3);
			break;
		case R.id.bt_change://转化按钮
			final String mp3name = etMp3.getText().toString().trim();
			final String wavname = etWav.getText().toString().trim();
			File file = new File(wavname);
			int size = (int) file.length();
			Log.e("文件大小：", size+"");
			if ("".equals(mp3name) || "".equals(wavname)) {
				Toast.makeText(getApplicationContext(), "路径不能为空", 0).show();
				return;
			}
			pd.setMessage("转化中....");
			pd.setProgressStyle(ProgressDialog.STYLE_HORIZONTAL);
			pd.setMax(size);
			pd.show();
			new Thread(){
				public void run() {
					convertmp3(wavname, mp3name);
					pd.dismiss();
				};
			}.start();
			
			break;
		case R.id.bt_get_version://获取版本号
			String verison = getLameVersion();
			Toast.makeText(getApplicationContext(), verison, 0).show();
			break;
		}
	}
	
	/**设置进度条的值*/
	public void setConvertProgress(int progress){
		pd.setProgress(progress);
	}
	
	
}
