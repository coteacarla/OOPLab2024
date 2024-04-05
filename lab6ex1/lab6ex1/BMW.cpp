#include "BMW.h"

BMW::BMW()
{
	speedSunny = 150;
	speedRain = 120;
	speedSnow = 80;
	fuel_capacity = 80;
	fuel_consumtion = 20;
}
const char* BMW::GetName()
{
	return "BMW";
}	
int BMW::getFinishTime()
{
	return time;
}
int BMW::raceTime(int lenght, Weather weather)
{

	if (weather == Weather::Rain)
		speed = speedRain;
	else if (weather == Weather::Sunny)
		speed = speedSunny;
	else
		speed = speedSnow;
	int min = 0;
	int copylenght = lenght;
	while (copylenght > speed)
	{
		min = min + 60;
		copylenght -= 100;
	}
	if (copylenght < speed && copylenght>0)
	{
		min = min + (int)((float)(lenght / speed) * 60);
	}
	this->time = min;
	if (this->Finish(lenght) == 1)
		return min;
	else
		return -1;
}
bool BMW::Finish(int lenght)
{//per 100km
	float parcurs = 0;
	float UsedFuel = 0;
	while (lenght > parcurs && lenght - parcurs >= 100)
	{
		parcurs = parcurs + 100;
		UsedFuel += fuel_consumtion;
	}
	if (lenght - parcurs < 100 && lenght - parcurs > 0)
	{
		UsedFuel += (fuel_capacity * (lenght - parcurs)) / 100;
	}
	if (UsedFuel <= fuel_capacity)
		return true;
	return false;
}