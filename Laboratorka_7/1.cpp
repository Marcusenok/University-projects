#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// Вариант 13: Дано целое число N (N>1). Составить алгоритм вывода наименьшего целого K, при котором выполняется неравенство 3K > N и самого значения 3K.


int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	int n=0, k=1; // объявление переменных

	
	while (n <= 1)                                         // ввод данных
	{
		printf("Введите число: ");	scanf_s("%d", &n); 
	}

	while(n >= (3 * k))
	{
		k++;
	}

	printf("3K=%d K=%d", 3 * k, k);

	return 1;
}