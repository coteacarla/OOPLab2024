#define _CRT_SECURE_NO_WARNINGS
#include "functii.h"
#include "Student.h"
#include <cstring>
#include<iostream>
char* Student::GetName()
{
	return this->name;
}
char Student::SetName(const char* s)
{
	strcpy_s(name, s);
	return 0;
}
float Student::GetMath()
{
	return this->m;
}
float Student::GetEng()
{
	return this->e;
}
float Student::GetHistory()
{
	return this->h;
}
void Student::SetMath(float x)
{
	if (x >= 1 && x <= 10)
	this->m = x;
}
void Student::SetHistory(float x)
{
	if (x >= 1 && x <= 10)
	this->h = x;
}
void Student::SetEng(float x)
{
	if(x>=1 && x<=10)
	this->e = x;
}
void Student::SetAvg()
{
	this->avr = (this->m + this->e + this->h) / 3;
}
float Student::GetAvg()
{
	return this->avr;
}