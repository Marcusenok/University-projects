#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// 13. Дано натуральное число n. Вычислить произведение  


int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	double p = 1;  // объявление переменных 
	int n = -1;
	
	while (n <= 0)                                         // ввод данных
	{
		printf("Введите число: ");	scanf_s("%d", &n);
	}

	for (int i = 1;i <= n; i++) // вычисление по формуле с счетчиком 
	{
		p = p * (1.0 + (1.0 / (i * i)));
		printf("i = %d    p = %lf\n", i, p);
	}

	printf("%lf", p); // вывод ответа 

	return 1;
}