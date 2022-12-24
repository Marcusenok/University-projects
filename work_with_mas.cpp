#include<iostream>
#include"mas.h"

void hands_input(struct RaggedArray& mas)// заполнение массива вручную
{
	printf("Введите количество строк(от 1 до 100): ");
	do scanf_s("%d", &mas.rows); while (mas.rows < 1 || mas.rows > 100);

	mas.data = (int**)malloc(sizeof(int*) * mas.rows);
	mas.cols = (int*)malloc(sizeof(int) * mas.rows);

	for (int i = 0; i < mas.rows; i++)
	{
		printf("Введите количество элементов в %d строчке(от 1 до 100): ", i);
		do scanf_s("%d", &mas.cols[i]);
		while (mas.cols[i] < 1 || mas.cols[i] > 100);
		mas.data[i] = (int*)malloc(sizeof(int) * mas.cols[i]);
	}

	for (int i = 0; i < mas.rows; i++)
		for (int j = 0; j < mas.cols[i]; j++)
		{
			printf("Введите значение элемента %d строки, %d столбца(от 1 до 10000): ", i, j);
			do scanf_s("%d", &mas.data[i][j]); 
			while (mas.data[i][j] < 1 || mas.data[i][j] > 10000);
		}
}

void input_array_txt(struct RaggedArray& mas)
{
	FILE* txt;

	if (fopen_s(&txt, "array.txt", "rt") != 0) exit(1);

	fscanf_s(txt, "%i", &mas.rows);
	mas.data = (int**)malloc(sizeof(int*) * mas.rows);
	mas.cols = (int*)malloc(sizeof(int) * mas.rows);
	for (int i = 0; i < mas.rows; i++)
	{
		fscanf_s(txt, "%i", &mas.cols[i]);
		mas.data[i] = (int*)malloc(sizeof(int) * mas.cols[i]);
	}

	for (int i = 0; i < mas.rows; i++)
		for (int j = 0; j < mas.cols[i]; j++)
		{
			fscanf_s(txt, "%d", &mas.data[i][j]);
		}
	fclose(txt);
}

void input_array_bin(struct RaggedArray& mas)
{
	FILE* f;

	if (fopen_s(&f, "array.bin", "rb") != 0) exit(1);

	fread(&mas.rows, sizeof(int), 1, f);
	mas.data = (int**)malloc(sizeof(int*) * mas.rows);
	mas.cols = (int*)malloc(sizeof(int) * mas.rows);

	for (int i = 0; i < mas.rows; i++)
	{
		fread(&mas.cols[i], sizeof(int), 1, f);
		mas.data[i] = (int*)malloc(sizeof(int) * mas.cols[i]);
	}

	for (int i = 0; i < mas.rows; i++)
		fread(mas.data[i], sizeof(int), mas.cols[i], f);

	fclose(f);
}

void choose_zapontnie_mas(struct RaggedArray& mas)
{
	printf("Как заполнить массив\n1)вручную\n2)из текстового файла\n3)из бинарного файла\n");
	int choose;
	do scanf_s("%d", &choose); while (choose < 1 || choose > 3);
	switch (choose)
	{
	case 1:
		hands_input(mas);
		break;
	case 2:
		input_array_txt(mas);
		break;
	case 3:
		input_array_bin(mas);
	default:
		break;
	}
}


void input_on_screen(struct RaggedArray& mas)
{
	for (int i = 0; i < mas.rows; i++)
	{
		for (int j = 0; j < mas.cols[i]; j++)
			printf("%5i", mas.data[i][j]);
		printf("\n");
	}
}

void element_mas(struct RaggedArray& mas)
{
	int num_row, num_cols, chose_izmenenie, new_element;
	printf("Введите строку: "); 
	do scanf_s("%d", &num_row);
	while (num_row < 1 || num_row > mas.rows);
	printf("Введите столбец: ");
	do scanf_s("%d", &num_cols); 
	while (num_cols < 1 || num_cols > mas.cols[num_row - 1]);

	printf("Элемент %i строки %i столбца = %i\n", num_row, num_cols, mas.data[num_row - 1][num_cols - 1]);

	printf("Изменить этот элемент 1)да 2) нет\n"); 
	do scanf_s("%d", &chose_izmenenie);
	while (chose_izmenenie < 1 || chose_izmenenie > 2);

	if (chose_izmenenie == 1)
	{
		printf("Введите значение элемента %d строки, %d столбца(от 1 до 10000): ", num_row, num_cols);
		do scanf_s("%d", &mas.data[num_row - 1][num_cols - 1]); 
		while (mas.data[num_row - 1][num_cols - 1] < 1 || mas.data[num_row - 1][num_cols - 1] > 10000);
	}

	input_on_screen(mas);
}

void output_rows_and_cols(struct RaggedArray& mas)
{
	printf("В массиве %i строк\n", mas.rows);
	for (int i = 0; i < mas.rows; i++)
	{
		printf("В %i строке %i элементов\n", i + 1, mas.cols[i]);
	}
}

void chooze_next_action(struct RaggedArray& mas)
{
	int choose;
	do {
		printf("\n1)Вывести или изменить элемент массива\n2)Количество строк и их длины\n3)Завершить работу\n");
		do scanf_s("%d", &choose); while (choose < 1 || choose > 3);
		switch (choose)
		{
		case 1:
			element_mas(mas);
			break;
		case 2:
			output_rows_and_cols(mas);
			break;
		default:
			break;
		}
	} while (choose != 3 || choose < 1 || choose > 3);
}

void outnput_array_in_txt(struct RaggedArray& mas)
{
	FILE* txt;

	if (fopen_s(&txt, "array.txt", "r+b") != 0) exit(1);

	fprintf_s(txt, "%d\n", mas.rows);

	for (int i = 0; i < mas.rows; i++)
	{
		fprintf_s(txt, "%d\n", mas.cols[i]);
	}

	for (int i = 0; i < mas.rows; i++)
	{
		for (int j = 0; j < mas.cols[i]; j++)
		{
			fprintf_s(txt, "%d ", mas.data[i][j]);
		}
		fprintf(txt, "\n");
	}
	fclose(txt);
}

void outnput_array_in_bin(struct RaggedArray& mas)
{
	FILE* bin;

	if (fopen_s(&bin, "array.bin", "wb") != 0) exit(1);

	fwrite(&mas.rows, sizeof(int), 1, bin);

	for (int i = 0; i < mas.rows; i++)
	{
		fwrite(&mas.cols[i], sizeof(int), 1, bin);
	}

	for (int i = 0; i < mas.rows; i++)
		for (int j = 0; j < mas.cols[i]; j++)
		{
			fwrite(&mas.data[i][j], sizeof(int), 1, bin);
		}

	fclose(bin);
}

void end(struct RaggedArray& mas)
{
	int chose_end_proga;
	printf("1)Заисать массив в текстовый файл\n2)Записать массив в бинарный файл\n3)Удалить массив\n");
	do scanf_s("%d", &chose_end_proga); while (chose_end_proga < 1 || chose_end_proga > 3);
	switch (chose_end_proga)
	{
	case 1:
		outnput_array_in_txt(mas);
		break;
	case 2:
		outnput_array_in_bin(mas);
		break;
	default:
		break;
	}

	for (int i = 0; i < mas.rows; i++)
		free(mas.data[i]);
	free(mas.data);
	free(mas.cols);
}