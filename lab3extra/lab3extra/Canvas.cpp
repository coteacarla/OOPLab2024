#include "Canvas.h"
#include<stdio.h>
#include<iostream>
#include <stdlib.h>
#include <stdarg.h>


Canvas::Canvas(int lines, int columns)
{
	this->lines = lines;
	this->columns = columns;
	Canvaspaint = new char* [lines];
	for (int i = 0; i < lines; i++)
	{
		Canvaspaint[i] = new char[columns];
		for (int j = 0; j < columns; j++)
			Canvaspaint[i][j] = ' ';
	}

}
void Canvas::set_pixel(int x, int y, char value)
{
	if (x < this->lines && y < this->columns)
		Canvaspaint[x][y] = value;
}
void Canvas::set_pixels(int count, ...)
{
	va_list vl;
	va_start(vl, count);
	int x, y, value;
	for (int i = 0; i < count*3; i++)
	{
		x= va_arg(vl, int);
		i++;
		y= va_arg(vl, int);
		i++;
		value = va_arg(vl, char);
		if (x < this->lines && y < this->columns)
			Canvaspaint[x][y] = value;

	}

	va_end(vl);
}
void Canvas::clear()
{
	for (int i = 0; i < lines; i++)
		for (int j = 0; j < columns; j++)
			Canvaspaint[i][j] = ' ';
}
void Canvas::print() const
{
	for (int i = 0; i < lines; i++)
	{
		for (int j = 0; j < columns; j++)
			printf("%c", Canvaspaint[i][j]);

		printf("\n");
	}
}