#pragma once
#include "Contact.h"
class Colleague : public Contact
{
private:
	std::string name="Stefan", company, address;
	long int phone;
public:
	std::string GetName() {
		return name;
	}
	void SetName(std::string person)
	{
		name = person;
	}
	std::string GetCompany() {
		return company;
	}
	std::string GetAddress() {
		return address;
	}
	long int GetPhone() {
		return phone;
	}
	bool IsFriend()
	{
		return false;
	}

};