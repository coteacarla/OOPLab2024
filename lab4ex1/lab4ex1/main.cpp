#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a[4] = { 5,11,33,68 };
	char s[] = "10,40,100,5,70";
	Sort Vector(s);
	Vector.Print();
	Vector.InsertSort(true);
	Vector.Print();
}