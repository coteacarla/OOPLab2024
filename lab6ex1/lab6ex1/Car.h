#pragma once
#include "Weather.h"

class Car
{
protected:
	int speed;
	int speedSunny;
	int speedRain;
	int speedSnow;
	int fuel_capacity;
	int fuel_consumtion;
	int time;
public:
	virtual int raceTime(int lenght, Weather weather)=0;
	virtual bool Finish(int lenght)=0;
	virtual const char* GetName()=0;
	virtual int getFinishTime()=0;

};

