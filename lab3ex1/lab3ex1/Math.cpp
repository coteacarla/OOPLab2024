#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>


int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	double s=0;
	s = a + b;
	return s;
}
int Math::Add(double a, double b, double c)
{
	double s;
	s = a + b + c;
	return s;
}
int Math:: Mul(int a, int b)
{
	return a * b;
}
 int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{

	return a*b;
}
int Math:: Mul(double a, double b, double c)
{
	double p;
	p = a * b * c;
	return p;
}
int Math::Add(int count, ...) // sums up a list of integers
{
	va_list vl;
	int s=0;
		va_start(vl, count); 
		for (int i = 0; i < count; i++)
			s = s + va_arg(vl, int);

	va_end(vl); 
	return s;
}
char* Math::Add(const char* s1, const char* s2)
{	
	int size = 0;
	if (strlen(s1) > strlen(s2))
		size = strlen(s1);
	else
		size = strlen(s2);
	char* s3 = new char[size + 1] {};
	strcpy(s3, " ");
	
	int t = 0;
	int l1 = strlen(s1)-1;
	int l2 = strlen(s2)-1;
	int c;
	while (size > 0)
	{
		c = 0;
		if (l1 >= 0)
		{
			c = c + s1[l1] - '0';
			l1--;
		}
		if (l2 >= 0)
		{
			c = c + s2[l2]- '0';
			l2--;
		}
		if (t == 1)
			c++;
		if (c / 10 != 0)
			t = 1;
		else
			t = 0;
		s3[size] = c%10 + '0';
size--;
	}
	if (strlen(s1) > strlen(s2))
		size = strlen(s1);
	else
		size = strlen(s2);
	;
	if (t == 1)
	{
		size++;
		s3[0] = '1';
		s3[size] = '\0';
	}
	else
	{
		for (int i = 0; i < size; i++)
			s3[i] = s3[i + 1];
		s3[size] = '\0';

	}

	return s3;
	delete s3;
	
}
