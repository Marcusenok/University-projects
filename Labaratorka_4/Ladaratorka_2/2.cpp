#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	// 13.	���� ����������� �����. ���������� �����, ���������� ��� ������������ � ��� ����� � �����. 

	setlocale(LC_ALL, "Russian"); // ������� ����

	int chislo, sotni, tisachi, decatki_tisach, dectki, new_chislo;

	printf("������� ����������� �����: ");  scanf_s("%d", &chislo); // ���� ������
	 
	sotni = (chislo / 100) % 10; // ���������� �����
	tisachi = (chislo / 1000) % 10; // ���������� �����
	decatki_tisach = chislo / 10000;
	dectki = chislo % 100;
	new_chislo = decatki_tisach * 10000 + sotni * 1000 + tisachi * 100 + dectki;
	
	printf("%d %d", chislo, new_chislo); // �����

	return 0;
}

// 1234567
// 234