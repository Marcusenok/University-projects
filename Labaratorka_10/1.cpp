#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

// 13. ����� ��� ������������� ������� ��������� 3x-4z=2y �� ��������� �� � �� �.


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	int a, b, p;  // ���������� ���������� 
                                       
	do {														// ���� ������(�������� "�� ������")
		printf("������� ����� a: ");	scanf_s("%d", &a);
		printf("������� ����� b: ");	scanf_s("%d", &b);
	} while(a > b);

	for(int i = a; i <= b; i++)	// ���������� �������� ���������� ��� ������� ���������� � ������� ��������� ������
	{
		for(int j = a; j <= b; j++)
		{
			for (int k = a; k <= b; k++)
			{
				if((3 * i - 4 * k) == (2 * j)) printf("x=%d z=%d y=%d\n", i, k, j); // �������� �� �������� ������ ���� ����� ����� ���������� 
			}
		}
	}

	return 1;
}