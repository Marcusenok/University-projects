#include<iostream>
#include"DynamicList.h"

using namespace std;

int main()
{
	system("chcp 1251");
	system("cls");

	DynamicList<int> List(100);
	DynamicList<double> List1(100.123);

	List + 11;
	List + 13;
	List1 + 3.2;
	List1 + 4.5;

	DynamicList<double> List2 = List1;

	List2 + 6.66;
	List2 + 7.77;

	List.Print();
	List1.Print();
	List2.Print();

	return 0;
}