#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <math.h>


void viborka(int &vvod)
{
	do {
		printf("Как вводим массив:\n1)клавиатура\n2)из файла\n3)случайными числами из указанного диапазона\n4)по заданной формуле\n5)бинарный файл\n");
		scanf_s("%d", &vvod);
	}while(vvod < 1 || vvod > 5);
}


void klaviatyra(double mas[100][100], int &sizei, int &sizej)
{
	do
	{
		printf("Количество строк i = ");
		scanf_s("%d", &sizei);
	} while (sizei <= 0 || sizei > 100);
	
	do
	{
		printf("Количество столбцов j = ");
		scanf_s("%d", &sizej);
	} while (sizej <= 0 || sizej > 100);

	for (int i = 0; i < sizei; i++)
	{
		for (int j = 0; j < sizej; j++)
		{
			printf("a[%d,%d] = ", i, j);
			scanf_s("%lf", &mas[i][j]);
		}
	}
}


void printmassiv(double mas[100][100], int sizei, int sizej)
{
	for (int j = 0; j < sizej; j++)
	{
		for (int i = 0; i < sizei; i++)
			printf("%10.2lf  ", mas[i][j]);
		printf("\n");
	}
}


void input_file(double mas[100][100], int& sizei, int& sizej)
{
	FILE* ft;
	if (fopen_s(&ft, "mas.txt", "rt") != 0)
	{
		printf("Файла нет");
		exit(1);
	}
	fscanf_s(ft, "%d", &sizei);
	fscanf_s(ft, "%d", &sizej);

	for (int i = 0; i < sizei; i++)
		for (int j = 0; j < sizej; j++)
			fscanf_s(ft, "%lf", &mas[i][j]);
	fclose(ft);
}


void output_file(double mas[100][100], int sizei, int sizej)
{
	FILE* f;

	if (fopen_s(&f, "mas.txt", "r+b") != 0)
	{
		printf("Файла нет");
		exit(1);
	}
	fprintf_s(f, "%d\n", sizei);
	fprintf_s(f, "%d\n", sizej);
	for (int i = 0; i < sizei; i++)
		for (int j = 0; j < sizej; j++)
			fprintf_s(f, "%lf\n", mas[i][j]);
	fclose(f);
}


void randomchick(double mas[100][100], int &sizei, int &sizej)
{
	int start, end;
	do
	{
		printf("Количество строк i = ");
		scanf_s("%d", &sizei);
	} while (sizei <= 0 || sizei > 100);

	do
	{
		printf("Количество столбцов j = ");
		scanf_s("%d", &sizej);
	} while (sizej <= 0 || sizej > 100);

	do
	{
		printf("Начало диапозона = ");
		scanf_s("%d", &start);
		printf("Конец диапозона = ");
		scanf_s("%d", &end);
	} while (start >= end);

	for (int i = 0; i < sizei; i++)
		for (int j = 0; j < sizej; j++)
			mas[i][j] = (rand() % (end - start) + start) + ((rand() % 100) / 100.0);
}

void formyla(double mas[100][100], int& sizei, int& sizej)
{
	do
	{
		printf("Количество строк i = ");
		scanf_s("%d", &sizei);
	} while (sizei <= 0 || sizei > 100);

	do
	{
		printf("Количество столбцов j = ");
		scanf_s("%d", &sizej);
	} while (sizej <= 0 || sizej > 100);


	for (int i = 1; i < sizei + 1; i++)
		for (int j = 1; j < sizej + 1; j++)
		{
			if(i < j)
				mas[i - 1][j - 1] = 4 / (i + j - 1);
			else if(i == j)
				mas[i - 1][j - 1] = 0;
			else
				mas[i - 1][j - 1] = 1 / (2 * i + 7 * j - 1);
		}
}


void podchet_symm(double mas[100][100], int sizei, int sizej)
{
	double symma = 0, kol_chesel = 0;
	for (int i = 0; i < sizei; i++)
		for (int j = i; j < sizej; j++)
		{
				symma += mas[i][j];
				kol_chesel += 1;
		}
	printf("Cреднее арифметическое элементов, лежащих выше главной диагонали матрицы = %8.2lf ", symma/kol_chesel);
}


void neodhodimo_vivodit(int &vivod_rezyltata)
{
	do {
		printf("Нужно выводить результат:\n1)не спасибо и так норм\n2)давай в бинарный что ли\n3)да в файл всё вывведи и норм");
		scanf_s("%d", &vivod_rezyltata);
	} while (vivod_rezyltata < 1 || vivod_rezyltata > 3);
}


void output_bin(double mas[100][100], int sizei, int sizej)
{
	FILE* f;

	if (fopen_s(&f, "save.bin", "w+"))
	{
		printf("Файла нет");
		exit(1);
	}
	fwrite(&sizei, sizeof(int), 1, f);
	fwrite(&sizej, sizeof(int), 1, f);
	for (int i = 0; i < sizei; i++)
		fwrite(mas[i], sizeof(double), sizej, f);
	fclose(f);
}


void input_bin(double mas[100][100], int& sizei, int& sizej)
{
	FILE* ft = NULL;
	if (fopen_s(&ft, "save.bin", "rt"))
	{
		printf("Файла нет");
		exit(1);
	}
	fread(&sizei, sizeof(int), 1, ft);
	fread(&sizej, sizeof(int), 1, ft);

	for (int i = 0; i < sizei; i++)
		fread(mas[i], sizeof(double), sizej, ft);
	fclose(ft);
}


int main()
{
	system("chcp 1251 > nul");
	srand(time(NULL));

	int sizei = 0, sizej = 0, vvod = 0, vivod_rezyltata = 0;
	double mas[100][100];
	
	viborka(vvod);

	switch (vvod)
	{
	case 1:
		klaviatyra(mas, sizei, sizej);
		break;

	case 2:
		input_file(mas, sizei, sizej);
		break;

	case 3:
		randomchick(mas, sizei, sizej);
		break;

	case 4:
		formyla(mas, sizei, sizej);
		break;

	case 5:
		input_bin(mas, sizei, sizej);
		break;

	default:
		printf("error");
		exit(0);
	}

	printmassiv(mas, sizei, sizej);

	podchet_symm(mas, sizei, sizej);

	neodhodimo_vivodit(vivod_rezyltata);

	switch (vvod)
	{
	case 1:
		printf("ПРИЯТНОЙ ДОРОГИ СТАЛКЕР!");
		break;

	case 2:
		output_file(mas, sizei, sizej);
		break;

	case 3:
		output_bin(mas, sizei, sizej);
		break;

	default:
		printf("error");
		exit(0);
	}

	return 1;
}