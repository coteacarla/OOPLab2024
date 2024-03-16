#include "Canvas.h"
#include<stdio.h>
#include<iostream>

Canvas::Canvas(int width, int height)
{
	this->width = width;
	this->height = height;
	Canvaspaint = new char* [height];
	for (int i = 0; i < this->height; i++)
	{
		Canvaspaint[i] = new char [width];
		for (int j = 0; j < this->width; j++)
			Canvaspaint[i][j] = ' ';
			
	}

}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
int r = ray;
	if(x<this->height && y<this->width)
		for (int i = 0; i < this->height; i++)
			for (int j = 0; j < this->width; j++)
	if ((i - x)*(i-x) + (j - y) *(j-y) >= r*(r - 1) && (i - x) * (i - x) + (j - y) * (j - y)  <= r*(r + 1))
		Canvaspaint[i][j] =ch;

}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int r = ray;
	if (x < this->height && y < this->width)
		for (int i = 0; i < this->height; i++)
			for (int j = 0; j < this->width; j++)
				if ((i - x) * (i - x) + (j - y) * (j - y) <= r * (r+1))
					Canvaspaint[i][j] = ch;
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    int linia1, coloana1, linia2, coloana2;
	linia1 = top;
	coloana1 = left;
	linia2= bottom;
	coloana2 = right;

	if (coloana1 < this->width && linia1 < this->height && coloana2 < this->width && linia2 < this->height)
	{
		for (int i = coloana1; i <= coloana2; i++)

		{
			Canvaspaint[linia1][i] = ch;
			Canvaspaint[linia2][i] = ch;
		}
		for (int i = linia1; i <= linia2; i++)
		{
			Canvaspaint[i][coloana1] = ch;
			Canvaspaint[i][coloana2] = ch;
		}

	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	int linia1, coloana1, linia2, coloana2;
	linia1 = top;
	coloana1 = left;
	linia2 = bottom;
	coloana2 = right;

	if (coloana1 < this->width && linia1 < this->height && coloana2 < this->width && linia2 < this->height)
	{
		for (int i = linia1; i <= linia2; i++)
			for (int j = coloana1; j <= coloana2; j++)
			Canvaspaint[i][j] = ch;
	

	}
}
void Canvas::SetPoint(int x, int y, char ch)
{
	if(x< this-> height && y< this-> width)
	Canvaspaint[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = x2 - x1;
	int dy = y2 - y1;
	int xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	int D = (2 * dx) - dy;
	int x = x1;

	for (int y = y1; y <= y2; y++) 
	{
		Canvaspaint[x][y]=ch;
		if (D > 0) 
		{
			x = x + xi;
			D = D + (2 * (dx - dy));
		}
		else 
		{
			D = D + 2 * dx;
		}
	}

}
void Canvas::Print()
{
	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
			printf("%c", Canvaspaint[i][j]);
	printf("\n");
}
}
void Canvas::Clear()
{
	for (int i = 0; i < this->height; i++)
		for (int j = 0; j < this->width; j++)
			Canvaspaint[i][j] = ' ';

}