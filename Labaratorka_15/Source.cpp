#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>


// 13.	������� ������ ������ � � ���������� � �����: ������� � ���� ����������� �� ������ 
// (����, �����, ���). ������� �� ����� ������� ���, ��� �������� �� ������ � ������������ ����. ���� (����, ����� � ���) �������� � ����������.


struct sotrudniki
{
    int familia;
    int data_den, data_mecaz, data_god;
};


int dlinna_massiva()
{
	int dlinna;
	do { printf("������� ���������� �����������: "); scanf_s("%d", &dlinna); } while (dlinna < 0 || dlinna > 100);
	return dlinna;
}


void Klava(sotrudniki *sotrudniki_list, int n)
{
	for (int i = 0; i < n; i++)  // ���� ������� ������� �����������
	{
		printf("������� ���� � ���������� �%d: ", i + 1);
		printf("���: ");         scanf_s("%d", &sotrudniki_list[i].familia);
		do { printf(" ����: ");  scanf_s("%d", &sotrudniki_list[i].data_den); } while (sotrudniki_list[i].data_den > 31 || sotrudniki_list[i].data_den < 1);
		do { printf(" �����: "); scanf_s("%d", &sotrudniki_list[i].data_mecaz);} while(sotrudniki_list[i].data_mecaz > 12 || sotrudniki_list[i].data_den < 1);
		do { printf(" ���: ");   scanf_s("%d", &sotrudniki_list[i].data_god); } while (sotrudniki_list[i].data_god > 2021);
	}
}

void input_vvod(sotrudniki* sotrudniki_list, int n)
{
	FILE* ft;
	ft = fopen("sotrudniki.txt", "rt");
	fscanf(ft, "%d", &n);
	for (int i = 0; i < n; i++) 
	{
		fscanf(ft, "%d %d %d %d %d", &sotrudniki_list[i].familia, &sotrudniki_list[i].data_den,
			&sotrudniki_list[i].data_mecaz, &sotrudniki_list[i].data_god);
	}
	fclose(ft);
}

void proverka_na_daty(sotrudniki* sotrudniki_list, int n)
{
	int den_proverki, mesac_proverki, god_proverki;
	printf("������� ���� ��������: ");  
	printf("����: ");  scanf_s("%d", &den_proverki);
	printf("�����: ");  scanf_s("%d", &mesac_proverki);
	printf("���: ");  scanf_s("%d", &god_proverki);

	for (int i = 0; i < n; i++)
	{
		if ((sotrudniki_list[i].data_den == den_proverki) && (sotrudniki_list[i].data_mecaz == mesac_proverki) && (sotrudniki_list[i].data_god == god_proverki))
			printf("��������� %d ����� �������� � ���� ����", sotrudniki_list[i].familia);
	}
}


void vivod_sotrudnikov(sotrudniki* sotrudniki_list, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ����� �������� %d.%d.%d", &sotrudniki_list[i].familia, &sotrudniki_list[i].data_den,
			&sotrudniki_list[i].data_mecaz, &sotrudniki_list[i].data_god);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian"); // ������� ����
	
	sotrudniki sotrudniki_list[100];

	int vvod_danix;

	int n = dlinna_massiva();
	printf("��� �� ������ ��������� ���������� � ����������� 1 �������; 2 � �����:  ");  scanf_s("%d", &vvod_danix);

	switch (vvod_danix) {
		case 1:
			Klava(sotrudniki_list, n);
			break;

		case 2:
			input_vvod(sotrudniki_list, n);
			break;

		default:
			printf("error");
			exit(0);
	}

	vivod_sotrudnikov(sotrudniki_list, n);

	proverka_na_daty(sotrudniki_list, n);

	return 1;
}
