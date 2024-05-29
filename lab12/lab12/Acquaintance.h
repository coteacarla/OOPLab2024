#pragma once
#include "Contact.h"

class Acquaintance : public Contact {
private:
	long int phone;
	std::string name="Marius";
public:
	std::string GetName() {
		return name;
	}
	void SetName(std::string person)
	{
		name = person;
	}
	long int GetPhone()
	{
		return phone;
	}
	bool IsFriend()
	{
		return false;
	}
};