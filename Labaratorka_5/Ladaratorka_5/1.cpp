#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	// 13. Дано целое число. Если оно отрицательно, возвести его в квадрат, в противном случае извлечь из него корень.

	int a; // объявление переменных

	printf("a = "); scanf_s("%d", &a); // ввод данных

	if (a > 0)
	{
		a = sqrt(a);
		printf("Так как а больше 0 то => a = %d", a);
	}
	else
	{
		a = a * a;
		printf("Так как а меньше 0 то => a = %d", a);
	}

	return 0;
}