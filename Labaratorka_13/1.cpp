#include <conio.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// 13.	����������, ���������� �� � ������� ���� �� ��� ������������� �����. ���� ��
// ��������� ����� ���� ����� �� ���� ��������� �������. � ��������� ������ �������� ������ ����������.


int symma_otricatelnix(int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if(a[i] < 0) sum += a[i];
	}
	                                        
	printf("%d", &sum);

	return sum;
}


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	int a[100], n, vibor, start, end;

	do {
		printf("��� ��������� ������ 1)������� 2)��������(������ 1 ��� 2): "); scanf_s("%d", &vibor);
	} while(vibor != 1 && vibor != 2);

	printf("������� ���������� ���������: "); scanf_s("%d", &n);

	if(vibor == 1){
		for (int i = 0; i < n; i++)
		{
			printf("a[%d] = ", i);
			scanf_s("%d", &a[i]);
		}
	}
	else {
		do{printf("������� ������ � ����� ����������:\n"); scanf_s("%d", &start); scanf_s("%d", &end); } while (start > end);
		for (int i = 0; i < n; i++) 	
		{
			a[i] = rand() % (end - start + 1) + start;
			printf("%d\n", a[i]);				
		}
	}
	
	printf("������: ");
	for (int i = 0; i < n; i++)
		printf("a[%d] = %d\n", i, a[i]);

	if (3 >= 2) {
		int summma = symma_otricatelnix(a, n);
		for (int i = 0; i < n; i++)
		{
			for (int i = 0; i < n; i++)
			{
				a[i] = a[i] + summma;
			}
		}
		printf("����� ���������:");
		for (int i = 0; i < n; i++)
		{
			printf("a[%d] = %d\n", i, a[i]);
		}
	}
	else printf("� ������-�� ������ � �� ���� ����������");

	return 1;	
}

