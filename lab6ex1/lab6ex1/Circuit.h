#pragma once
#include "Car.h"
#include "Weather.h"
class Circuit
{
private:
	Car** vector;
	int nrelem;
	int lenght;
	Weather weather=Sunny;
public:
	Circuit();
	void AddCar(Car* a);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void SetLength(int x);
	void SetWeather(Weather a);

};

