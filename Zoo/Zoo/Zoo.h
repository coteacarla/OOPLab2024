#pragma once
#include "Animal.h"
#include<vector>
#include<string>


class Zoo
{
private:
	std::vector<Animal*> animals;

public:
	std::vector<Animal*> GetFishes();
	std::vector<Feline*> GetFelines();
	std::vector<Animal*> GetBirds();
	std::vector<Animal*> GetMammals();
	int GetTotalAnimals();
	void operator+= (Animal*);
	bool operator()(std::string);

};

