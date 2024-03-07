#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
using namespace std;
<<<<<<< HEAD
char str[101], s[101][101], cuv[101];
int l, lg, nr;
int i, j;
int main()
{
    scanf("%101s", str);
    l = 0;
    nr = 0;
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
        {
            if (nr == 0)
                strcpy(s[0], cuv);//pun cuv in matrice
            else
            {
                for (i = 0; i < nr; i++)
                    if (l > strlen(s[i]))
                    {
                        nr++;//cresc nr cuv
                        for (j = nr; j > i; j--)// interschimb cuv
                            strcpy(s[j], s[j - 1]);

                        strcpy(s[i], cuv);

                    }
            }
            l = 0;//l redevine 0
            strcpy(cuv, NULL); //cuv e null
        }
        else
            if (str[i] != ' ')
            {
                char j[5];
                j[0] = str[i];
                j[1] = 0;
                strcpy(cuv, j);
                while (str[i] != ' ')
                {
                    j[0] = str[i];
                    j[1] = 0;
                    l++;
                    i++;
                    strcat(cuv, j);
                }
            }

    }
    for (i = 0; i <= nr; i++)
    {
        printf("%30s", s[i]);
        printf("\n");
    }


=======

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
>>>>>>> c818f1fc43485f4a3b1ecb3e9684c31610fff335
}
