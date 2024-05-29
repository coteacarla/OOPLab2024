#include "Zoo.h"
#include "Animal.h"
#include "Feline.h"
std::vector<Animal*>  Zoo::GetFishes()
{
	std::vector<Animal*> toreturn;
	for (auto i : this->animals)
		if (i->IsAFish() == 1)
			toreturn.push_back(i);
	return toreturn;
}
std::vector<Feline*> Zoo::GetFelines()
{
	std::vector<Feline*> toreturn;
	for (auto i : this->animals)
		if (i->GetName() == "Tiger" || i->GetName() == "Lion")
			toreturn.push_back((Feline*)i);
	return toreturn;

}
std::vector<Animal*>  Zoo::GetBirds()
{
	std::vector<Animal*> toreturn;
	for (auto i : this->animals)
		if (i->IsABird() == 1)
			toreturn.push_back(i);
	return toreturn;

}
std::vector<Animal*>  Zoo::GetMammals()
{
	std::vector<Animal*> toreturn;
	for (auto i : this->animals)
		if (i->IsAMammal() == 1)
			toreturn.push_back(i);
	return toreturn;

}
int  Zoo::GetTotalAnimals()
{
	int total = 0;
	for (auto i : this->animals)
		total++;
	return total;
}
void  Zoo::operator+= (Animal* random)
{
	animals.push_back(random);
}
bool Zoo::operator() (std::string AnimalName)
{
	for (auto i : this->animals)
		if (i->GetName() == AnimalName)
			return true;
	return false;

}