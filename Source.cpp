#include<iostream>
#include"mas.h"

// 6.������ ����������� ������������.���������� ����� ������������ ����� �����������.���������� ��������� �����
// ������������ ������������ �������� ��������.

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