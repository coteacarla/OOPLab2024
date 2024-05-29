#pragma once
#include "Contact.h"
class Friend : 
	public Contact
{
private:
	
	long int phone;
	std::string address="Salcami nr11", name="Andrei", date="10.01.2003";
public:
	std::string GetName() {
		return name;
	}
	void SetName(std::string person)
	{
		name = person;
	}
	std::string GetAddress() {
		return address;
	}
	std::string GetData() {
		return date;
	}
	long int GetPhone() {
		return phone;
	}
	bool IsFriend()
	{
		return true;
	}
	
    
};