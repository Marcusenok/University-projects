#include<iostream>
#include "Figures.h"
using namespace std;


int main()
{
	Figure f1(10, 10, 10, 10);
	cout << "\nx = " << f1.GetX() << "\ny = " << f1.GetY();
	cout << "\ncolor = " << f1.GetColor() << "\nsize = " << f1.GetSize();

	f1.Show();

	Circle f2(11, 11, 11, 11);
	cout << "\nx = " << f2.GetX() << "\ny = " << f2.GetY();
	cout << "\ncolor = " << f2.GetColor() << "\nsize = " << f2.GetRadius();

	f2.Show();

	return 0;
}