#pragma once
class Number
{
private:
	int base=10;
	char* numar;
	public:
		Number(const char* value, int base); // where base is between 2 and 16
		Number(int value);
		~Number();
		Number(const Number& d);// add operators and copy/move constructor
		Number(Number&& d);
		Number& operator-- ();
		Number operator-- (int value);
		Number operator= (Number n1);
		Number operator= (int value);
		Number operator= (const char* value);
		bool operator< (Number& n1);
		bool operator> (Number& n1);
		bool operator>= (Number& n1);
		bool operator<= (Number& n1);
		bool operator== (Number& n1);
		char operator[] (int value);
		void SwitchBase(int newBase);
		friend Number operator+ (Number n1, Number n2);
		friend void operator+= (Number& n1, Number n2);
		friend Number operator- (Number n1, Number n2);
		void Print();
		int  GetDigitsCount(); // returns the number of digits for the current number
		int  GetBase(); // returns the current base

};

