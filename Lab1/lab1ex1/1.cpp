#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <cstring> 
using namespace std;
char str[21];
long int x, s, n;
int i;

int main()
{
	FILE* file;
	auto succes = fopen_s(&file, "ini.txt", "r");
	///sau FILE *file =  fopen("ini.txt","r");
	if (file == NULL) {
		printf("Couldn't open the file!!");
		return 0;
	}
	while ( fgets(str,21,file)!=NULL)
	{
		x = 0;
		for (i = 0; i< strlen(str)-1; i++)
			x = x * 10 + (str[i] - '0');
		s = s + x;
	}
	printf("%d", s);

	fclose(file);
	return 0;
}