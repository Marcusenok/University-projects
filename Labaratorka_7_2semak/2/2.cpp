#include<malloc.h>
#include<iostream>

// 5. ��������� ����� ������ ������.����� ���������� ���� ����� ������������ ��������.
// �������� ������������� ������� � ������� ������� ����������

void input_rows_and_cols(int& rows, int& cols) // ���������������� ���� �������� �������
{
	printf("���������� ����� - ");    scanf_s("%d", &rows);
	printf("���������� �������� - "); scanf_s("%d", &cols);
}


int main() {
	system("chcp 1251");
	int rows, cols, maxi = 0, chetchik = 0;
	int** a1;

	input_rows_and_cols(rows, cols);

	a1 = (int**)malloc(rows * sizeof(int*)); // ��������� ������ ��� ��������� �� ������
	for (int i = 0; i < rows; i++) // ���� �� �������
	{
		a1[i] = (int*)malloc(cols * sizeof(int)); // ��������� ������ ��� �������� �����
		for (int j = 0; j < cols; j++) // ���� �� ��������
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a1[i][j]);
		}
	}

	for (int i = 0; i < rows; i++) // ����� ��������� ������� ���� �� �������
	{
		for (int j = 0; j < cols; j++) // ���� �� ��������
		{
			printf("%d ", a1[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < rows; i++) // ������� ����� �����
	{
		for (int j = 0; j < cols; j++) // ���� �� ��������
		{
			chetchik += a1[i][j];
		}
		printf("����� %d ������ = %d", i, chetchik);
		if (chetchik > maxi) maxi = chetchik;
		chetchik = 0;
		printf("\n");
	}

	printf("������������ ����� ������ = %d", maxi);

	return 0;
}