package cn.itcast.callbinary;

import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;

import android.app.Activity;
import android.os.Bundle;

public class DemoActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        try {
        	//Process  process = Runtime.getRuntime().exec("/data/data/hello");
        	Process  process = Runtime.getRuntime().exec("date");
        	InputStream is = process.getInputStream();
        	DataInputStream dis = new DataInputStream(is);
        	String result ;
        	StringBuilder sb = new StringBuilder();
        	 while((result = dis.readLine())!=null){
        		 sb.append(result);
        		 sb.append("\n");
        	 }
        	System.out.println(sb.toString());
        	
		} catch (Exception e) {
			e.printStackTrace();
		}
    }
}