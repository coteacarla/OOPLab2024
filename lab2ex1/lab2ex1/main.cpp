#include "NumberList.h"
int main()
{
	NumberList lista;
	lista.Init();
	lista.Add(5);
	lista.Add(3);
	lista.Add(7);
	lista.Sort();
	lista.Print();

}