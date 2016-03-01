package com.kenny.monitor;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

public class MyView extends View{

	private int bottom;
	private Paint paint;
	
	public MyView(Context context,int bottom,int color) {
		super(context);
		this.bottom = bottom;
		paint = new Paint();
		paint.setColor(color);
		paint.setStrokeWidth(10);
	}
	
	//所有android下的view控件的显示其实是通过onDraw来绘制的
	//canvas代表的是屏幕的画布
	@Override
	protected void onDraw(Canvas canvas) {
		canvas.drawRect(20, 20 , 100 , bottom ,paint);
		super.onDraw(canvas);
		
	}
}
