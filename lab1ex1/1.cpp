#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <cstring> 
using namespace std;
char str[101],s[101][101],cuv[101];
int l,lg,nr;
int i;
int main()
{
	scanf("%101s", str);
	l = 0;
	nr = 0;
	for (i = 0; i < strlen(str), i++)
	{
		if (str[i] == ' ')
		{
			if (nr == 0)
				strcpy(s[0], cuv)
			else
			{
				for (i = 0; i < nr; i++)
					if (l > strlen(s[i])
					{
						nr++;
						for (j = nr; j > i; j--)
							strcpy(s[j], s[j - 1]);

							strcpy(s[i], cuv);

					}
			}
			    l=0;
				cuv='/n';
		}
		else
		                if (str[i] != ' ')
						{
							strcpy(cuv, s[i]);
							while (str[i] != ' ')
							{
								l++;
								i++;
								strcat(cuv, str[i]);
							}
						}
			
	}
	for (i = 0; i <= nr; i++)
		printf("%30s", s[i]);
	printf("\n\n");





}