#include<iostream>


// 13.	������� ������ ������ � � ���������� � �����: ������� � ���� ����������� �� ������ 
// (����, �����, ���). ������� �� ����� ������� ���, ��� �������� �� ������ � ������������ ����. ���� (����, ����� � ���) �������� � ����������.

// �������� ���������
struct sotrudniki
{
	char familia[100];
	int data_den, data_mecaz, data_god;
};

// ������� ��� ����������� ���������� ����������� � ������ �� ������� ����������
int dlinna_massiva()
{
	int dlinna;
	do { printf("������� ���������� �����������: "); scanf_s("%d", &dlinna); } while (dlinna < 0 || dlinna > 100);
	return dlinna;
}

// ���� ���������� � ����������� � ����������
void Klava(sotrudniki* sotrudniki_list, int& n)
{	
	for (int i = 0; i < n; i++)  // ���� ������� ������� �����������
	{
		printf("������� ���� � ���������� �%d ", i + 1);
		printf("���: ");         scanf_s("%s", &sotrudniki_list[i].familia, 100);
		do { printf("����: ");  scanf_s("%d", &sotrudniki_list[i].data_den); } while (sotrudniki_list[i].data_den > 31 || sotrudniki_list[i].data_den < 1);
		do { printf("�����: "); scanf_s("%d", &sotrudniki_list[i].data_mecaz); } while (sotrudniki_list[i].data_mecaz > 12 || sotrudniki_list[i].data_den < 1);
		do { printf("���: ");   scanf_s("%d", &sotrudniki_list[i].data_god); } while (sotrudniki_list[i].data_god > 2021);
	}
}

// ����� ���������� � �����������
void vivod_sotrudnikov(sotrudniki* sotrudniki_list, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s ����� �������� %d.%d.%d\n", sotrudniki_list[i].familia, sotrudniki_list[i].data_den, sotrudniki_list[i].data_mecaz, sotrudniki_list[i].data_god);
	}
}

// �������� �� ����
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
			printf("��������� %s ����� �������� � ���� ����\n", sotrudniki_list[i].familia);
	}
	printf("�������� ��������");
}

// ���� ���������� � ����������� �� �����
void input_vvod(sotrudniki* sotrudniki_list, int& n)
{
	FILE* ft;
	if (fopen_s(&ft, "sotrudniki.txt", "rt") != 0)
	{
		printf("����� ���");
		exit(1);
	}

	fscanf_s(ft, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf_s(ft, "%s %d %d %d", &sotrudniki_list[i].familia, 100, &sotrudniki_list[i].data_den,
			&sotrudniki_list[i].data_mecaz, &sotrudniki_list[i].data_god);
	}
	fclose(ft);
}

// ���� ���������� � ����������� �� ��������� �����
void input_bin(sotrudniki* sotrudniki_list, int& n)
{
	FILE* ft = NULL;
	if (fopen_s(&ft, "save.bin", "rt"))
	{
		printf("����� ���");
		exit(1);
	}

	fread(&n, sizeof(int), 1, ft);
	fread(&sotrudniki_list, sizeof(sotrudniki), n, ft);
	fclose(ft);
}


// ���� ���������� � ����������� � ��������� �����
void output_bin(sotrudniki* sotrudniki_list, int n)
{
	FILE* ft = NULL;
	if (fopen_s(&ft, "save.bin", "wt"))
	{
		printf("����� ���");
		exit(1);
	}

	fwrite(&n, sizeof(int), 1, ft);
	fwrite(&sotrudniki_list, sizeof(sotrudniki), n, ft);
	fclose(ft);
}



int main()
{
	system("chcp 1251 > nul");

	sotrudniki sotrudniki_list[100];

	int vvod_danix, n;

	printf("��� �� ������ ��������� ���������� � ����������� \n1 �������\n2 � �����\n3 �������� ����: ");  scanf_s("%d", &vvod_danix);

	switch (vvod_danix) {
	case 1:
		n = dlinna_massiva();
		Klava(sotrudniki_list, n);
		break;

	case 2:
		input_vvod(sotrudniki_list, n);
		break;

	case 3:
		input_bin(sotrudniki_list, n);
		break;

	default:
		printf("error");
		exit(0);
	}


	vivod_sotrudnikov(sotrudniki_list, n);
	proverka_na_daty(sotrudniki_list, n);

	if (vvod_danix == 1 || vvod_danix == 2) {
		int konec;
		printf("��������� ��������� ������ � �������� ����?(1-�� 2-���)");
		if (scanf_s("%d", &konec) == 1)
		{
			output_bin(sotrudniki_list, n);
		}
		else printf("�����");
	}

	return 0;
}