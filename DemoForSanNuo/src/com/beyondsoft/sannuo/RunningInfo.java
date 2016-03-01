package com.beyondsoft.sannuo;

public class RunningInfo {
	public native int StartRunning();
	public native int StopRuning();
	public native String GetWelcomInfo();
	
	public native short GetRotateSpeed(); //转速
	public native short GetVehicleSpeed(); //车速
	public native short GetWaterTemperature();//水温
	public native short GetAirDamper();//节气门
	public native short GetTirePressure();//̥胎压
	public native short GetOilMass();//油量
	public native short GetOilWear();//油耗
	public native short GetRemainingOil();//剩余油量
	
	static 
	{
		System.loadLibrary("CarRunning");
	}

}
