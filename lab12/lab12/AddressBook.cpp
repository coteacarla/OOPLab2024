#include "AddressBook.h"
#include"Contact.h"
#include"Friend.h"
#include<vector>

bool AddressBook::SearchName(std::string person) {
	for (auto i : this->agenda)
		if (i->GetName() == person)
			return true;
	return false;

 }
std::vector<Friend*> AddressBook::GetFriends() {
	std::vector<Friend*> toreturn;
	for (auto i : this->agenda)
		if (i->IsFriend() == 1)
			toreturn.push_back((Friend*)i);
	return toreturn;

}
std::vector<Contact*> AddressBook::Delete(std::string person) {
	std::vector<Contact*> toreturn;
	for (auto i : this->agenda)
		if (i->GetName() != person)
			toreturn.push_back(i);
	agenda = toreturn;
	return agenda;


}
void AddressBook:: operator +=(Contact* person) 
{
	agenda.push_back(person);
}