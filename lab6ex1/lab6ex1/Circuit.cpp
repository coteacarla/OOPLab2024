#include "Circuit.h"
#include "Car.h"
#include<iostream>

Circuit::Circuit()
{
	this->vector = new Car* [100 * sizeof(Car)];
	this->lenght = 0;
	this->nrelem = 0;
    this->weather = Weather::Sunny;
	
}
void Circuit::AddCar(Car* a)
{
	if (this->nrelem < 100) 
		this->vector[this->nrelem++] = a;
}
void Circuit::Race()
{
	int i;
	for (i = 0; i <this->nrelem; i++)
		vector[i]->raceTime(this->lenght,weather);
}
void Circuit::ShowFinalRanks()
{
	int i, j;
	Car** rezultate = new Car * [nrelem];
	for (i = 0; i < nrelem; i++)
		rezultate[i] = vector[i];
	for (i = 0; i < nrelem - 1; i++)
		for (j = i + 1; j < nrelem; j++)
			if (rezultate[i]->getFinishTime() > rezultate[j]->getFinishTime())
				std::swap(rezultate[i], rezultate[j]);
	printf("Rezultate finale:\n");
	for (i = 0; i < nrelem; i++)
		if (rezultate[i]->getFinishTime() >= 0)
			printf("Masina %s a terminat in %d minute\n", rezultate[i]->GetName(), rezultate[i]->getFinishTime());
	delete[] rezultate;
}
void Circuit::ShowWhoDidNotFinish()
{
	int i;
	bool ok = true;
	for (i = 0; i < this->nrelem; i++)
	{
		vector[i]->raceTime(this->lenght, weather);
		if (vector[i]->getFinishTime() <0)
		{ 
		printf("Masina %s nu a terminat\n", vector[i]->GetName());
		ok = false;
		}	
	}
	if (ok == true)
		printf("Toate masinile au terminat cursa");
}
void Circuit::SetLength(int x)
{
	this->lenght = x;
}
void Circuit::SetWeather(Weather a)
{
	this->weather= a;
}