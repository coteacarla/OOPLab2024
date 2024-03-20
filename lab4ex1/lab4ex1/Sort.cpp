#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include<stdio.h>
#include<iostream>
#include<cstring>
#include<stdlib.h>
#include<stdarg.h>


 Sort::Sort(int n, int mini, int maxi)
{
	 v = new int[n];
	 srand(time(0));
	 this->count = n;
	 for (int i = 0; i < n; i++)
		 this->v[i] = (rand() % (maxi - mini) + 1) + mini;
}

 Sort::Sort(int a[10001], int nr)
 {
	 v = new int[nr];
	 for (int i = 0; i < this->count; i++)
		 this->v[i] = 0;
	 this->count = nr;
	 for (int i = 0; i < nr; i++)
		 this->v[i] = a[i];
 }
 Sort::Sort(int nrparametrii...)
 {
	 v = new int[nrparametrii];
	 va_list vl;
	 this->count = nrparametrii;
	 va_start(vl,nrparametrii);
	 for (int i = 0; i < nrparametrii; i++)
	 {
		 this->v[i] = va_arg(vl, int);
	 }
	 va_end(vl);
 }
 Sort::Sort(char* s)
 {
	 v = new int[strlen(s)];
	 this->count = 0;
	 char* p;
	 int nr;
	 int putere;
	 p = strtok(s, ",");
	 while (p)
	 { 
		 this->count++;
		 nr = 0;
		 putere = 1;
		 for (int i = strlen(p) - 1; i >= 0; i--)
		 {
			 nr = nr + putere * (p[i] - '0');
			 putere = putere * 10;
		 }
		 this->v[this->count - 1] = nr;
		 p = strtok(NULL, ",");
	 }

 }
 Sort::Sort() : v (new int[6] {1, 2, 3, 4, 5, 6}) 
 {
	 this->count = 6;
 }

void  Sort::InsertSort(bool ascendent )
{
	int i, elem, j;
	if(ascendent==true)
	for (i = 1; i < this->count; i++)
	{
		elem = this->v[i];
		j = i - 1;
		while (j >= 0 && this->v[j] > elem)
		{
			this->v[j + 1] = this->v[j];
			j--;
		}
		this->v[j + 1] = elem;
	}
	else
	for (i = 1; i < this->count; i++)
		{
			elem = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] < elem)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = elem;
		}
}
int partition(int v[],bool ascendent, int left, int right)
{

	int pivot = v[right];
	int i = (left - 1);

	for (int j = left; j <= right; j++)
	{
		if (ascendent == true)
		{
			if (v[j] < pivot)
			{
				i++;
				std::swap(v[i], v[j]);
			}
		}
		else
		if (v[j] > pivot)
			{
				i++;
				std::swap(v[i], v[j]);
			}

	}
	std::swap(v[i + 1], v[right]);
	return (i + 1);
}


void quickSort(int v[],bool ascendent, int left, int right)
{

	if (left < right)
	{
		int pivot = partition(v,ascendent, left, right);
		quickSort(v, ascendent,left, pivot - 1);
		quickSort(v, ascendent,pivot + 1, right);
	}
}

void  Sort::QuickSort(bool ascendent )
{
	quickSort(v, ascendent, 0, this->count - 1);
}
void  Sort::BubbleSort(bool ascendent)
{
	int i, j;
	bool ok;
	int aux;
	if (ascendent == true)
		for (i = 0; i < this->count - 1; i++)
		{
			ok = false;
			for (j = 0; j < this->count - i - 1; j++)
				if (this->v[j] > this->v[j + 1])
				{
					aux = this->v[j];
					this->v[j] = this->v[j + 1];
					this->v[j + 1] = aux;
					ok = true;
				}
			if (ok == false)
				break;
		}
	else
		for (i = 0; i < this->count - 1; i++)
		{
			ok = false;
			for (j = 0; j < this->count - i - 1; j++)
				if (this->v[j] < this->v[j + 1])
				{
					aux = this->v[j];
					this->v[j] = this->v[j + 1];
					this->v[j + 1] = aux;
					ok = true;
				}
			if (ok == false)
				break;
		}

	
}
void  Sort::Print()
{
	for (int i = 0; i < this->count; i++)
		printf("%d ", this->v[i]);
	printf("\n");

}
int   Sort::GetElementsCount()
{
	return this->count;
}
int   Sort::GetElementFromIndex(int index)
{
	if (index >= this->count)
	{
		printf("Eroare, nu exista suficiente elemente");
		return 0;
	}
	return this->v[index];
}

