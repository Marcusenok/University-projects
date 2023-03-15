#include <iostream>
#include "Vector.h"

using namespace std;


int main()
{
	Vector a(2);
	Vector b(2);

	cin >> a;
	cin >> b;

	cout << a[1] << "\n";

	cout << (a < b) << "\n";
	cout << (a != 3.4) << "\n";
	return 0;
}