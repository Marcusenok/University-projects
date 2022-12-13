#include<malloc.h>
#include<iostream>

// 5. Вычислить сумму каждой строки.Среди полученных сумм найти максимальное значение.
// Динамическое выделение памяти для двумерных массивов в виде одномерного массива

void input_rows_and_cols(int& rows, int& cols) // пользовательский ввод размеров массива
{
	printf("Количество строк - ");    scanf_s("%d", &rows);
	printf("Количество столбцов - "); scanf_s("%d", &cols);
}


int main(){
	system("chcp 1251");
	int rows, cols, maxi = 0, chetchik = 0;
	int* a1;

	input_rows_and_cols(rows, cols);

	a1 = (int*)malloc(rows * cols * sizeof(int));
	for (int i = 0; i < rows; i++) // цикл по строкам
	{
		for (int j = 0; j < cols; j++) // цикл по столбцам
		{
			printf("mas[%d][%d] = ", i, j);
			scanf_s("%d", (a1 + i * cols + j));
		}
	}

	for (int i = 0; i < rows; i++) // вывод элементов массива цикл по строкам
	{
		for (int j = 0; j < cols; j++) // цикл по столбцам
		{
			printf("%d ", *(a1 + i * cols + j));
		}
		printf("\n");
	}

	for (int i = 0; i < rows; i++) // подсчёт суммы строк
	{
		for (int j = 0; j < cols; j++) // цикл по столбцам
		{
			chetchik += *(a1 + i * cols + j);
		}
		printf("Сумма %d строки = %d", i, chetchik);
		if (chetchik > maxi) maxi = chetchik;
		chetchik = 0;
		printf("\n");
	}

	printf("Максимальная сумма строки = %d", maxi);

	return 0;
}
