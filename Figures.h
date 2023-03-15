#include<iostream>
using namespace std;


class Figure
{
protected:
	int x = 0;
	int y = 0;
	double size = 1;
	int color = 1;

	void Init();
public:
	Figure();
	Figure(int _x, int _y, int _color, double _size);
	int GetColor();
	int GetX();
	int GetY();
	double GetSize();
	void SetColor(int _color);
	void MoveTo(int _x, int _y);
	void SetX(int _x);
	void SetY(int _y);
	void SetSize(double _size);
	virtual void Show() = 0;
	virtual int GetType() = 0;
};

class Circle : public Figure 
{
private:
	int radius = 1;
public:
	Circle();
	Circle(int _x, int _y, int _color, int _radius);
	int GetRadius();
	void Show();
	int GetType();
};

class Rectangle : public Figure
{
private:
	int w = 0;
	int h = 0;
public:
	Rectangle();
	Rectangle(int _x, int _y, int _color, int _w, int _h);
	int GetH();
	int GetW();
	void SetH(int _h);
	void SetW(int _w);
	void Show();
	int GetType();
};

class Triangle : public Figure
{
private:
	int a = 0;
	int b = 0;
	int c = 0;
public:
	Triangle();
	Triangle(int _x, int _y, int _color, int _a, int _b, int _c);
	int GetA();
	int GetB();
	int GetC();
	void SetA(int _a);
	void SetB(int _b);
	void SetC(int _c);
	void Show();
	int GetType();
};