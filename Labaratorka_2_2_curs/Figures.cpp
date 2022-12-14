#include <iostream>
#include "Figures.h"

#pragma region Figure
Figure::Figure()
{
	Init();
}

Figure::Figure(int _x, int _y, int _color, double _size )
{
	Init();
	color = _color;
	x = _x;
	y = _y;
	size = _size;
}

void Figure::Init()
{
	color = 1;
	x = y = 1;
	size = 1;
}

int Figure::GetColor()
{
	return color;
}

int Figure::GetX()
{ 
	return x;
}

int Figure::GetY()
{
	return y;
}

double Figure::GetSize() 
{ 
	return size;
}

void Figure::MoveTo(int _x, int _y) 
{ 
	SetX(_x); 
	SetY(_y); 
}

void Figure::SetX(int _x)
{ 
	if (_x > 0) x = _x; 
}

void Figure::SetY(int _y) 
{ 
	if (_y > 0) x = _y;
}

void Figure::SetSize(double sz) 
{ 
	if (sz > 0) size = sz; 
}

void Figure::Show()
{
	cout << "\nFigure\n";
}

#pragma endregion

#pragma region Circle
Circle::Circle()
{
	radius = 1;
	Init();
}

Circle::Circle(int _x, int _y, int _color, int _radius)
{
	Init();
	x = _x;
	y = _y;
	color = _color;
	radius = _radius;
}

int Circle::GetRadius()
{
	return radius;
}

void Circle::SetRadius(int _radius)
{
	radius = _radius;
}

void Circle::Show()
{
	cout << "\nCircle\n";
}
#pragma endregion