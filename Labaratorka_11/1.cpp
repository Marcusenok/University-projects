#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	int n, st = 1;
	double s = 0, x;
	do {														// ���� ������(�������� "�� ������")
		printf("������� ����� n: ");	scanf_s("%d", &n);
		printf("������� ����� x: ");	scanf_s("%lf", &x);
	} while(n <= 1 || x <= 1);

	for(int i = 1; i <= n; i++)  // ��������� ����� ������������������
	{
		if (i != 1)  s += 2 * log10(x);  // ��� i=1 ����� �� ������������� ������� ����������� ����� ����� i �� ����� 0 
	}
	printf("%.3lf", s); // ����� ������

	return 1;
}