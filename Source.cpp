#include<iostream>
#include"mas.h"

// 6.Массив представлен дескриптором.Количество строк определяется полем дескриптора.Количество элементов строк
// определяется динамическим массивом размеров.

int main()
{
	system("chcp 1251 > NULL");

	RaggedArray mas;

	choose_zapontnie_mas(mas);

	input_on_screen(mas);

	chooze_next_action(mas);

	end(mas);

	system("pause");
	return 0;
}