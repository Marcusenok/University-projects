#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	// 13.	��� ������ ����� � ������. �������� ������ ����� ����� � ������� X ���������� Y ���������� Z ������.

	int bait, kbait, megabait; // ���������� ����������
	
	printf("������� ����� ����: ");  scanf_s("%d", &bait); // ���� ������

	kbait = (bait / 1024) % 1024;
	megabait = bait / 1024 / 1024; // ���������� ��������
	bait = bait % 1024;
	
	printf("%d �������� %d ��������  %d ����", megabait, kbait, bait);
	return 0;
}
