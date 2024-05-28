//
// pch.h
//

#pragma once

#include "gtest/gtest.h"

template <typename T>
void insertsort(T* arr, int size)
{
	int n = size;
	int i;
	for (i = 0; i <= size; i++)
	{
		T elem = arr[i];
		int j = i + 1;
		while (arr[j] > elem && j > 0)
		{
			arr[j + 1] = arr[j];
			j++;
		}
		arr[j] = elem;
	}

}