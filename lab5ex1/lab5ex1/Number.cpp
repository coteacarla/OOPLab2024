#include "Number.h"
#include<cstring>
#include<iostream>

Number::Number(const char* value, int base)
{
	this->base = base;
	this->numar = new char [strlen(value)] {};
	if(base<=16 && base>0)
	for (int i = strlen(value); i >= 0; i--)
		this->numar[i] = value[i];
	this->numar[strlen(value)] = '\0';
}
Number& Number::operator-- ()
{
this->numar[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}
Number Number::operator-- (int value)
{
	for (int i = 0; i < this->GetDigitsCount(); i++)
		this->numar[i] = this->numar[i + 1];
	this->numar[this->GetDigitsCount() - 1] = '\0';
	return (*this);
}
Number Number::operator= (Number n1)
{
	this->numar = n1.numar;
	this->base = n1.base;
	return (*this);
}
Number::Number(int value)
{	
	this->base = 10;
	int putere = 1;
	int log = 0;
	while (value >= putere)
	{
		putere = putere * this->base;
		log++;
	}
	//aloc spatiu
	int index;
	index = log;
	this->numar = new char[index];
	for (int i = 0; i <index; i++)
		this->numar[i] = ' ';
	this->numar[index] = '\0';

	//pun in numar
	for (int i = index - 1; i >= 0; i--)
	{
		if (value % this->base < 10)
			this->numar[i] = (value % this->base) + '0';
		else
			this->numar[i] = (value % this->base) - 10 + 'A';
		value = value / this->base;

	}

}
Number Number::operator= (int value)
{
	int putere = 1;
	int log = 0;
	while (value >= putere)
	{
		putere = putere * this->base;
		log++;
	}
	//aloc spatiu
	int index;
	index = log;
	for (int i = 0; i <= log; i++)
		this->numar[i] = ' ';
	this->numar[log + 1] = '\0';

	//pun in numar
	for (int i = index - 1; i >= 0; i--)
	{
		if (value % this->base < 10)
			this->numar[i] = (value % this->base) + '0';
		else
			this->numar[i] = (value % this->base) - 10 + 'A';
		value = value / this->base;

	}
	return (*this);
}
Number Number::operator= (const char* value)
{ 
	
	this->numar = new char[strlen(value)];
	int index = strlen(value);
	for (int i = index - 1; i >= 0; i--)
			this->numar[i] = value[i];
	this->numar[index] = '\0';

	return (*this);

}
bool Number::operator< (Number& n1)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = this->GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (this->numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * this->base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n1.GetDigitsCount()-1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (this->numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * this->base;
	}
	if (nr1baza10 < nr2baza10)
		return true;
	else
	return false;

}
bool Number::operator> (Number& n1)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = this->GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (this->numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * this->base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n1.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (this->numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * this->base;
	}
	if (nr1baza10 > nr2baza10)
		return true;
	else
		return false;

}
bool Number::operator<= (Number& n1)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = this->GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (this->numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * this->base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n1.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (this->numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * this->base;
	}
	if (nr1baza10 <= nr2baza10)
		return true;
	else
		return false;

}
bool Number::operator== (Number& n1)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = this->GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (this->numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * this->base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n1.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (this->numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * this->base;
	}
	if (nr1baza10 == nr2baza10)
		return true;
	else
		return false;

}
bool Number::operator>= (Number& n1)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = this->GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (this->numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * this->base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n1.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (this->numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * this->base;
	}
	if (nr1baza10 >= nr2baza10)
		return true;
	else
		return false;

}
Number::~Number()
{
	numar = nullptr;
	delete[] numar;
}
Number::Number(const Number& d)
{
	this->numar = new char[sizeof(d.numar)];
	this->base = d.base;
	this->numar=d.numar;

}
Number::Number(Number&& d)
{
	this->base = d.base;
	this->numar = new char[sizeof(d.numar)];
	char* copy = d.numar;
	d.numar = nullptr;
	this->numar = copy;

}

// add operators and copy/move constructor
Number operator+ (Number n1, Number n2)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = n1.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (n1.numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * n1.base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n2.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (n2.numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * n2.base;
	}
	nr1baza10 += nr2baza10;

	int maxBase = n1.base;
	if (n2.base > maxBase)
		maxBase = n2.base;

	int putere = 1;
	int log = 0;
	while (nr1baza10 >= putere)
	{
		putere = putere * maxBase;
		log++;
	}

	//aloc spatiu
	int index;
	index = log;
	Number rez("0", 10);
	rez.numar = new char[log] {};
	rez.base = maxBase;
	for (int i = 0; i <= log; i++)
		rez.numar[i] = ' ';
	rez.numar[log + 1] = '\0';

	//pun in numar
	for (int i = index - 1; i >= 0; i--)
	{
		if (nr1baza10 % maxBase < 10)
			rez.numar[i] = (nr1baza10 % maxBase) + '0';
		else
			rez.numar[i] = (nr1baza10 % maxBase) - 10 + 'A';
		nr1baza10 = nr1baza10 / maxBase;

	}
	return rez;
	
}
Number operator- (Number n1, Number n2)
{
	int nr2putere = 1;
	int nr2baza10 = 0;
	for (int i = n1.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr2baza10 = nr2putere * (n1.numar[i] - '0') + nr2baza10;
		nr2putere = nr2putere * n1.base;
	}
	int nr1putere = 1;
	int nr1baza10 = 0;
	for (int i = n2.GetDigitsCount() - 1; i >= 0; i--)
	{
		nr1baza10 = nr1putere * (n2.numar[i] - '0') + nr1baza10;
		nr1putere = nr1putere * n2.base;
	}
	nr2baza10 -= nr1baza10;

	int maxBase = n1.base;
	if (n2.base > maxBase)
		maxBase = n2.base;

	int putere = 1;
	int log = 0;
	while (nr2baza10 >= putere)
	{
		putere = putere * maxBase;
		log++;
	}

	//aloc spatiu
	int index;
	index = log;
	Number rez("0", 10);
	rez.numar = new char[log] {};
	rez.base = maxBase;
	for (int i = 0; i <= log; i++)
		rez.numar[i] = ' ';
	rez.numar[log + 1] = '\0';

	//pun in numar
	for (int i = index - 1; i >= 0; i--)
	{
		if (nr2baza10 % maxBase < 10)
			rez.numar[i] = (nr2baza10 % maxBase) + '0';
		else
			rez.numar[i] = (nr2baza10 % maxBase) - 10 + 'A';
		nr2baza10 = nr2baza10 / maxBase;

	}
	return rez;

}
void operator+= (Number& n1, Number n2)
{
	n1=n1+n2;
}
void Number::SwitchBase(int newBase)
{
	//transform baza b->baza10
	// baza10->newbase
	int putere = 1;
	int baza10 = 0;
	int bazab = 0;
	for (int i = strlen(this->numar) - 1; i >= 0; i--)
	{
		baza10 = putere * (this->numar[i] - '0') + baza10;
		putere = putere * this->base;
	}
	//aflu logaritmul ca sa stiu cat spatiu folosesc

	int log=0;
	putere = 1;
	while (baza10 >= putere)
	{
		putere = putere * newBase;
		log++;
	}

	//aloc spatiu
    int index;
	index =log;
	this->numar = new char[log] {};
	this->base = newBase;
//golesc memoria
    for(int i=0;i<=log;i++)
		this->numar[i] = ' ';
    this->numar[log+1] = '\0';
//pun in numar
	for(int i=index-1;i>=0;i--)
	{
		if(baza10 % newBase<10)
		this->numar[i] = (baza10 % newBase) + '0';
		else 
	    this->numar[i] = (baza10 % newBase)-10 + 'A';
		baza10 = baza10 / newBase;

	}


}
char Number::operator[] (int value)
{
	return this->numar[value];
}
void Number::Print()
{
	for (int i =0; i<strlen(this->numar); i++)
		printf("%c", numar[i]);
	printf("\n");
}
int  Number::GetDigitsCount()
{
	return strlen(this->numar);
}
int  Number::GetBase()
{
	return this->base;
}


