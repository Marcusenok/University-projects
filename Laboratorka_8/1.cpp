#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

// 13. Ќаписать программу определени€ максимального четного числа из последовательности положительных чисел, вводимых с клавиатуры.
// ¬вод данных завершить после того, как пользователь введет 0 или любое отрицательное число.


int main()
{
	setlocale(LC_ALL, "Russian"); // русский €зык
	
	int f, maxi = 0;
	
	do {
		printf("f = ");
		scanf_s("%d", &f);
		if (f > maxi && ((f % 2) == 0)) maxi = f;
	} while (f > 0);

	printf("%d  ", maxi);

	return 1;
}