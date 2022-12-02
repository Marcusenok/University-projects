#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian"); // русский €зык
 
	double x; // объ€вление переменных

	printf("x = ");  scanf_s("%lf", &x); // ввод данных

	if (x < 0)  x = 1;
	else if (x >= 0 && x < 1)  x = 2 / (x + 2);
	else x = 2 * exp(x);

	printf("x = %lf", x);

	return 0;
}