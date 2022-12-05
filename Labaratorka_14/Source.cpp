#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// 13.	Определить, содержатся ли в массиве хотя бы два отрицательных числа. Если да
// прибавить сумму этих чисел ко всем элементам массива. В противном случае оставить массив неизменным.


int proverka_na_otrisatelnie(int a[], int n)  // функция для определения количества отрицательных чисел в массиве 
{
	int kol_otrisatelnix = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0) kol_otrisatelnix += 1;
	}

	return kol_otrisatelnix;
}


int summa_otrisatelnix(int a[], int n)    // функция для вычисления суммы отрицательных чисел в массиве 
{
	int summa_otrisatelnix = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0) summa_otrisatelnix += a[i];
	}

	return summa_otrisatelnix;
}


int dlinna_massiva()
{
	int dlinna; 
	do { printf("Введите количество элементов: "); scanf_s("%d", &dlinna); } while (dlinna < 0 || dlinna > 100); 
	return dlinna;
}


void output_file(int a[], int n)
{
	FILE* f = fopen("input.txt", "w+");
	fprintf(f, "%d \n", n);
	for (int i = 0; i < n; i++)
		fprintf(f, "%d\n ", a[i]);
	fclose(f);
}


int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	int a[100], n, start, end, vvod_massiva;  // объявление переменных

	printf("1 вручную; 2 рандомно; 3 с файла:  ");  scanf_s("%d", &vvod_massiva);

	switch(vvod_massiva){
		case 1:
			n = dlinna_massiva();
			for (int i = 0; i < n; i++)  // ввод массива вручную поэлементно
			{
				printf("a[%d] = ", i);
				scanf_s("%d", &a[i]);
			}
			break;
		
		case 2:
			n = dlinna_massiva();
			do { printf("Введите начало и конец промежутка:\n"); scanf_s("%d", &start); scanf_s("%d", &end); } while (start > end); // проверка на коректность промежутка
			for (int i = 0; i < n; i++)         // рандомное заполнение массива
			{
				a[i] = rand() % (end - start + 1) + start;
			}
			break;
		
		case 3:
			FILE * ft;
			ft = fopen("input.txt", "rt");
			fscanf(ft, "%d", &n);
			for (int i = 0; i < n; i++) fscanf(ft, "%d", &a[i]);
			fclose(ft);
			break;

		default:
			printf("error");
			exit(0);
	}

	printf("Массив: ");   // вывод массива
	for (int i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, a[i]);

	if (proverka_na_otrisatelnie(a, n) >= 2) // прибавление суммы отрицательных чисел к каждому элементу массива и вывод массива
	{
		int summm = summa_otrisatelnix(a, n);
		for (int i = 0; i < n; i++) a[i] += summm;
		
		printf("Массив после изменений: ");
		for (int i = 0; i < n; i++)
			printf("a[%d] = %d\n", i, a[i]);
		
		int vibor_sohronenia;
		printf("Сохранить изменения 1 да; 2 нет:  "); scanf_s("%d", &vibor_sohronenia);
		switch(vibor_sohronenia){
		case 1:
			output_file(a, n);
			printf("Изменения сохранены в input.txt");
			break;
		
		default:
			printf("the end");
			exit(0);
		}
	}
	else printf("А делать-то ничего и не надо получается");

	return 1;
}