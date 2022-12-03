#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// 13. Найти все целочисленные решения уравнения 3x-4z=2y на интервале от А до В.


int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	int a, b, p;  // объявление переменных 
                                       
	do {														// ввод данных(проверка "на дурака")
		printf("Введите число a: ");	scanf_s("%d", &a);
		printf("Введите число b: ");	scanf_s("%d", &b);
	} while(a > b);

	for(int i = a; i <= b; i++)	// перебираем значения переменных для подбора подходящих с помощью вложенных циклов
	{
		for(int j = a; j <= b; j++)
		{
			for (int k = a; k <= b; k++)
			{
				if((3 * i - 4 * k) == (2 * j)) printf("x=%d z=%d y=%d\n", i, k, j); // проверка на верность ответа если верно вывод переменных 
			}
		}
	}

	return 1;
}