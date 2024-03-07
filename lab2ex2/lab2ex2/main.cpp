#include "functii.h"
#include "Student.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include<iostream>

using namespace std;
int main()
{
	Student c1, c2;
	c1.SetName("Ionel");
	c1.SetEng(9);
	c1.SetMath(8);
	c1.SetHistory(9);
	c1.SetAvg();
	c2.SetName("Gigel");
	c2.SetEng(7);
	c2.SetMath(7);
	c2.SetHistory(7);
	c2.SetAvg();
	printf("%s\n", c1.GetName());
	printf("%f\n", c1.GetAvg());
	printf("%s\n", c2.GetName());
	printf("%f\n", c2.GetAvg());
	printf("%d", compareByAvr(&c1,&c2));

	return 0;
}