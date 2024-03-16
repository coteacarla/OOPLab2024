#pragma once

class Movie
{
private:
	char name[256];
	int year;
	int lenght;
	float score;
public:
	void set_name(const char* s);
	void set_score(float x);
	void set_year(int x);
	void set_lenght(int y);
	char* get_name();
	float get_score();
	int get_year();
	int get_lenght();
};

