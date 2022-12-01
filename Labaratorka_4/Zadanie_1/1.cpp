#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian"); // русский язык

	// 13.	Дан размер файла в байтах. Выразить размер этого файла в формате X мегабайтов Y килобайтов Z байтов.

	int bait, kbait, megabait; // объявление переменных
	
	printf("Введите число байт: ");  scanf_s("%d", &bait); // ввод данных

	kbait = (bait / 1024) % 1024;
	megabait = bait / 1024 / 1024; // количество мегабайт
	bait = bait % 1024;
	
	printf("%d мегабайт %d килобайт  %d байт", megabait, kbait, bait);
	return 0;
}
