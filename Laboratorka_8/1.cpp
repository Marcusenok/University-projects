#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

// 13. �������� ��������� ����������� ������������� ������� ����� �� ������������������ ������������� �����, �������� � ����������.
// ���� ������ ��������� ����� ����, ��� ������������ ������ 0 ��� ����� ������������� �����.


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����
	
	int f, maxi = 0;
	
	do {
		printf("f = ");
		scanf_s("%d", &f);
		if (f > maxi && ((f % 2) == 0)) maxi = f;
	} while (f > 0);

	printf("%d  ", maxi);

	return 1;
}