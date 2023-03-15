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

void Figure::SetSize(double _size)
{
	if (_size > 0) size = _size;
}

void Figure::SetColor(int _color)
{
	color = _color;
}
#pragma endregion

#pragma region Circle
Circle::Circle()
{
	Init();
	radius = 1;
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

void Circle::Show()
{
	cout << "\nCircle\n";
}

int Circle::GetType()
{
	return 1;
}
#pragma endregion

#pragma region Rectangle
Rectangle::Rectangle()
{
	Init();
	int w = 1;
	int h = 1;
}

Rectangle::Rectangle(int _x, int _y, int _color, int _w, int _h)
{
	Init();
	x = _x;
	y = _y;
	color = _color;
	w = _w;
	h = _h;
}

int Rectangle::GetH()
{
	return h;
}

void Rectangle::SetH(int _h)
{
	h = _h;
}

int Rectangle::GetW()
{
	return w;
}

void Rectangle::SetW(int _w)
{
	w = _w;
}

void Rectangle::Show()
{
	cout << "\nRectangle\n";
}

int Rectangle::GetType()
{
	return 2;
}
#pragma endregion

#pragma region Triangle
Triangle::Triangle()
{
	Init();
	int a = 1;
	int b = 1;
	int c = 1;
}

Triangle::Triangle(int _x, int _y, int _color, int _a, int _b, int _c)
{
	Init();
	x = _x;
	y = _y;
	color = _color;
	a = _a;
	b = _b;
	c = _c;
}

int Triangle::GetA()
{
	return a;
}

int Triangle::GetB()
{
	return b;
}

int Triangle::GetC()
{
	return c;
}

void Triangle::SetA(int _a)
{
	a = _a;
}

void Triangle::SetB(int _b)
{
	b = _b;
}

void Triangle::SetC(int _c)
{
	c = _c;
}

void Triangle::Show()
{
	cout << "\nTriangle\n";
}

int Triangle::GetType()
{
	return 3;
}
#pragma endregion