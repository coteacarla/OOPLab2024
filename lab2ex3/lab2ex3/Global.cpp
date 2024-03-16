#include "Global.h"
#include "Movie.h"
#include<cstring>
#include<iostream>

int movie_compare_name(Movie* ep4, Movie* ep5)
{
	if (strcmp(ep4->get_name(), ep5->get_name()) > 0)
		return 1;
	if (strcmp(ep4->get_name(), ep5->get_name()) < 0)
		return -1;
	return 0;
}
int movie_compare_year(Movie* ep4, Movie* ep5)
{
	if (ep4->get_year() > ep5->get_year())
		return 1;
	if (ep4->get_year() < ep5->get_year())
		return -1;
	return 0;
}
int movie_compare_score(Movie* ep4, Movie* ep5)
{
	if (ep4->get_score() > ep5->get_score())
		return 1;
	if (ep4->get_score() < ep5->get_score())
		return -1;
	return 0;
}
int movie_compare_length(Movie* ep4, Movie* ep5)
{
	if (ep4->get_lenght() > ep5->get_lenght())
		return 1;
	if (ep4->get_lenght() < ep5->get_lenght())
		return -1;
	return 0;

}
int movie_compare_passed_years(Movie *ep4, Movie *ep5)
{
	if (ep4->get_year() < ep5->get_year())
		return -1;
	if (ep4->get_year() > ep5->get_year())
		return 1;
	return 0;
}