#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	// 13. ���� ����� �����. ���� ��� ������������, �������� ��� � �������, � ��������� ������ ������� �� ���� ������.

	int a; // ���������� ����������

	printf("a = "); scanf_s("%d", &a); // ���� ������

	if (a > 0)
	{
		a = sqrt(a);
		printf("��� ��� � ������ 0 �� => a = %d", a);
	}
	else
	{
		a = a * a;
		printf("��� ��� � ������ 0 �� => a = %d", a);
	}

	return 0;
}