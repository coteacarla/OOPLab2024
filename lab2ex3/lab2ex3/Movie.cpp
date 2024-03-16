#include "Movie.h"
#include <cstring>

void Movie::set_name(const char* s)
{
	strcpy_s(this->name,s);
}
void Movie::set_score(float x)
{
	if(x>=1 && x<=10)
	this-> score = x;
}
void Movie::set_year(int x)
{
	this->year = x;
}
void Movie::set_lenght(int y)
{
	this->lenght = y;
}
char* Movie::get_name()
{
	return this->name;
}
int Movie::get_lenght()
{
	return this->lenght;
}
float Movie::get_score()
{
	return this->score;
}
int Movie::get_year()
{
	return this->year;
}

