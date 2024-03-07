#include "functii.h"
#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<iostream>

int compareByMath(Student* c1, Student* c2)
{
	if (c1->GetName() > c2->GetName())
		return 1;
	if (c1->GetName() < c2->GetName())
		return -1;
	return 0;

}
int compareByEng(Student* c1, Student* c2)
{
	if (c1->GetEng() > c2->GetEng())
		return 1;
	if (c1->GetEng() < c2->GetEng())
		return -1;
	return 0;
}
int compareByHistory(Student* c1, Student* c2)
{
	if (c1->GetHistory() > c2->GetHistory())
		return 1;
	if (c1->GetHistory() < c2->GetHistory())
		return -1;
	return 0;
}
int compareByAvr(Student* c1, Student* c2)
{
	if (c1->GetAvg() > c2->GetAvg())
		return 1;
	if (c1->GetAvg() < c2->GetAvg())
		return -1;
	return 0;
}
int compareByName(Student* c1, Student* c2)
{
	if (strcmp(c1->GetName(), c2->GetName()) > 0)
		return 1;
	if (strcmp(c1->GetName(), c2->GetName()) < 0)
		return -1;
	return 0;

}

