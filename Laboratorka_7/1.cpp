#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


// ������� 13: ���� ����� ����� N (N>1). ��������� �������� ������ ����������� ������ K, ��� ������� ����������� ����������� 3K > N � ������ �������� 3K.


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����

	int n=0, k=1; // ���������� ����������

	
	while (n <= 1)                                         // ���� ������
	{
		printf("������� �����: ");	scanf_s("%d", &n); 
	}

	while(n >= (3 * k))
	{
		k++;
	}

	printf("3K=%d K=%d", 3 * k, k);

	return 1;
}