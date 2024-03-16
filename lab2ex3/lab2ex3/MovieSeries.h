#pragma once
#include "Movie.h"
#include <cstring>
class MovieSeries
{
private:
     Movie movie[16];
	 int count;
public:
	void init();
	bool add(Movie &film);
	void print();
	void sort();

};

