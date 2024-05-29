#pragma once
#include"Contact.h"
#include"Friend.h"
#include<vector>
class AddressBook
{
private:
	std::vector<Contact*> agenda;
public:
	    bool SearchName(std::string);
		std::vector<Friend*> GetFriends();
		std::vector<Contact*> Delete(std::string);
        void operator += (Contact*);
};

