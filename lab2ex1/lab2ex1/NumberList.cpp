#include "NumberList.h"

void NumberList::Init()
{
    count = 0;
}
bool NumberList::Add(int x)
{
    if (count > 9)
        return false;
    else
    {
       count++;
       numbers[count] = x;
       return true;

    }
}
void NumberList::Print()
{
    for (int i = 1; i <= count; i++)
        printf("%d ", numbers[i]);
    printf("\n");
}
void NumberList::Sort()
{
    for(int i=1;i<count;i++)
        for(int j=i+1;j<=count;j++)
            if (numbers[i] > numbers[j])
            {
                int aux;
                aux = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = aux;
            }
}