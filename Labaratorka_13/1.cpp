#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// 13.	Определить, содержатся ли в массиве хотя бы два отрицательных числа. Если да
// прибавить сумму этих чисел ко всем элементам массива. В противном случае оставить массив неизменным.


int symma_otricatelnix(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[i] < 0) sum += a[i];
	}
	                                        
	printf("%d", &sum);

	return sum;
}


int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	int a[100], n, vibor, start, end;

	do {
		printf("Как заполнить массив 1)вручную 2)рандомно(ввести 1 или 2): "); scanf_s("%d", &vibor);
	} while(vibor != 1 && vibor != 2);

	printf("Введите количество элементов: "); scanf_s("%d", &n);

	if(vibor == 1){
		for (int i = 0; i < n; i++)
		{
			printf("a[%d] = ", i);
			scanf_s("%d", &a[i]);
		}
	}
	else {
		do{printf("Введите начало и конец промежутка:\n"); scanf_s("%d", &start); scanf_s("%d", &end); } while (start > end);
		for (int i = 0; i < n; i++) 	
		{
			a[i] = rand() % (end - start + 1) + start;
			printf("%d\n", a[i]);				
		}
	}
	
	printf("Массив: ");
	for (int i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, a[i]);

	if (3 >= 2) {
		int summma = symma_otricatelnix(a, n);
		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < n; i++)
			{
				a[i] = a[i] + summma;
			}
		}
		printf("После изменений:");
		for (int i = 0; i < n; i++)
		{
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
	else printf("А делать-то ничего и не надо получается");

	return 1;	
}

