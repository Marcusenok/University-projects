#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// 13. ���� ����������� ����� n. ��������� ������������  


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	double p = 1;  // ���������� ���������� 
	int n = -1;
	
	while (n <= 0)                                         // ���� ������
	{
		printf("������� �����: ");	scanf_s("%d", &n);
	}

	for (int i = 1;i <= n; i++) // ���������� �� ������� � ��������� 
	{
		p = p * (1.0 + (1.0 / (i * i)));
		printf("i = %d    p = %lf\n", i, p);
	}

	printf("%lf", p); // ����� ������ 

	return 1;
}