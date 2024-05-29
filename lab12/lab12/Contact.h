#pragma once
#include<string>

class Contact {
public:
	virtual std::string GetName() = 0;
	virtual void SetName(std::string) = 0;
	virtual bool IsFriend() = 0;
};