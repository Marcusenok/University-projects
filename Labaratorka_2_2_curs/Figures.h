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
	void MoveTo(int _x, int _y);
	void SetX(int _x);
	void SetY(int _y);
	void SetSize(double sz);
	void Show();
};

class Circle : public Figure 
{
private:
	int radius = 1;
public:
	Circle();
	Circle(int _x, int _y, int _color, int _radius);
	int GetRadius();
	void SetRadius(int _radius);
	void Show();
};