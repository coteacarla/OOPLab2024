#pragma once
#include "Car.h"
#include "Weather.h"
class RangeRover :
    public Car
{
private:
	int speedSunny = 150;
	int speedRain = 120;
	int speedSnow = 80;
	int fuel_capacity = 80;
	int fuel_consumtion = 20;
public:
	RangeRover();
	virtual const char* GetName();
	virtual int raceTime(int lenght, Weather weather);
	virtual bool Finish(int lenght);
	virtual int getFinishTime();
};

