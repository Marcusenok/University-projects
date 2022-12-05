#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// 13.	����������, ���������� �� � ������� ���� �� ��� ������������� �����. ���� ��
// ��������� ����� ���� ����� �� ���� ��������� �������. � ��������� ������ �������� ������ ����������.


int proverka_na_otrisatelnie(int a[], int n)  // ������� ��� ����������� ���������� ������������� ����� � ������� 
{
	int kol_otrisatelnix = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0) kol_otrisatelnix += 1;
	}

	return kol_otrisatelnix;
}

int summa_otrisatelnix(int a[], int n)    // ������� ��� ���������� ����� ������������� ����� � ������� 
{
	int summa_otrisatelnix = 0;

	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0) summa_otrisatelnix += a[i];
	}

	return summa_otrisatelnix;
}


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	int a[100], n, vibor, start, end;  // ���������� ����������

	do { printf("������� ���������� ���������: "); scanf_s("%d", &n); } while (n < 0 || n > 100);

	printf("��� ��������� ������ 1)������� 2)��������: "); scanf_s("%d", &vibor);

	switch(vibor)
	{
		case 1:
			for (int i = 0; i < n; i++)  // ���� ������� ������� �����������
			{
				printf("a[%d] = ", i);
				scanf_s("%d", &a[i]);
			}
			break;
		case 2:
			do { printf("������� ������ � ����� ����������:\n"); scanf_s("%d", &start); scanf_s("%d", &end); } while (start > end); // �������� �� ����������� ����������
			for (int i = 0; i < n; i++)         // ��������� ���������� �������
			{
				a[i] = rand() % (end - start + 1) + start;
			}
			break;
		default:
			printf("error");
			exit(0);
	}

	printf("������: ");   // ����� �������
	for (int i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, a[i]);

	if (proverka_na_otrisatelnie(a, n) >= 2) // ����������� ����� ������������� ����� � ������� �������� ������� � ����� �������
	{
		int summm = summa_otrisatelnix(a, n);
		for (int i = 0; i < n; i++) a[i] += summm;
		printf("������ ����� ���������: ");
		for (int i = 0; i < n; i++)
			printf("a[%d] = %d\n", i, a[i]);
	}
	else printf("� ������-�� ������ � �� ���� ����������");

	return 1;
}