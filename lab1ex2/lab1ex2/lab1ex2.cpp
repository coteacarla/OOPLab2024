#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;

bool caracter(char a)
{
    if (a >= 'a' && a <= 'z' || a >= 'A' && a <= 'Z')
        return true;
    return false;
}

int lungime(char s[])
{
    int i, cnt = 0;
    for (i = 0; s[i]; i++)
    {
        cnt++;
    }
    return cnt;
}
char l[100][100];

void sortare(int cnt)
{
    int n = cnt;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (lungime(l[i]) < lungime(l[j]))
                swap(l[i], l[j]);
}

int main()
{
    char s[100];
    int i = 0;
    while (scanf("%c", &s[i]) && s[i] != '\n')
        i++;
    s[i] = '\0';
    int n = i;
    i = 0;
    int cnt = 0, j = 0;

    while (s[i])
    {
        if (caracter(s[i]))
        {
            l[cnt][j] = s[i];
            i++;
            j++;
        }
        else
        {
            l[cnt][j] = NULL;
            cnt++;
            i++;
            j = 0;
        }
    }
    l[cnt][j] = NULL;
    sortare(cnt);
    char aux[100];
    for (int i = 0; i <= cnt; i++) {

        printf("%s\n", l[i]);
    }
    return 0;
}
