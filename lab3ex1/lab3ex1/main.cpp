#include "Math.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
	Math Math;

	printf("%d\n",Math.Add(2.5,3.0));
	printf("%s\n", Math.Add("9", "22"));
}