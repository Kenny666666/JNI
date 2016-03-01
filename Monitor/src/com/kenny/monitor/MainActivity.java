package com.kenny.monitor;

import java.util.Timer;
import java.util.TimerTask;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.widget.TextView;


public class MainActivity extends Activity {

	private Timer timer;
	private TimerTask task;
	
	private Handler handler = new Handler(){
		public void handleMessage(android.os.Message msg) {
			int pressure = (Integer) msg.obj;
			int color = getColor(pressure);
			if (color == 404) {
				//压力超过极限
				TextView tv = new TextView(MainActivity.this);
				tv.setTextColor(Color.RED);
				tv.setText("锅炉快要爆炸了快跑吧");
				//todo 播放报警声音
				setContentView(tv);
				timer.cancel();
				return;
			}
			MyView myView = new MyView(MainActivity.this, pressure, color);
			setContentView(myView);
		};
	};
	
	/**获取压力器压力*/
	public native int getPressure();
	static{
		System.loadLibrary("Hello");
	}
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        //获取锅炉压力，根据压力显示不同的内容
        timer = new Timer();
        task = new TimerTask() {
			
			@Override
			public void run() {
				int pressure = getPressure() % 300;
				//把压力显示到UI界面上
				Message msg = new Message();
				msg.obj = pressure;
				handler.sendMessage(msg);
			}
		};
		timer.schedule(task, 1000, 2000);
    }
    
    /**
     * 根据锅炉压力获取应该显示的颜色
     * @param pressure
     * @return
     */
    public int getColor(int pressure){
    	if (pressure <100) {
			return Color.GREEN;
		}else if (pressure <200) {
			return Color.YELLOW;
		}else if (pressure <280) {
			return Color.RED;
		}else {
			return 404;
		}
    }
}
