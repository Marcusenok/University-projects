#include <iostream>
#include <stdio.h>
// 4. ����������, ������� ��� � ������ ����������� �������� �����.


// ������� ��� ����������� ������ ������
int len(char* s)
{
	int l = 0;
	while (s[l] != '\0') {
		l++;
	}

	return l;
}


int main()
{
	system("chcp 1251 > nul"); // ��� ������ � ������� ������

	// ���������� ����������
	char str[256];
	char slovo[100];
	bool slovo_full = true;
	printf("������� ������: ");  gets_s(str);
	printf("������� ������������ �����: ");  gets_s(slovo);

	// �������� �� ������� ����� � ������
	for (int i = 0; i < len(str); i++)
	{
		slovo_full = true;
		for (int j = 0; j < len(slovo); j++)
		{
			if (str[i + j] == ' ' || str[i + j] != slovo[j])
			{
				slovo_full = false;
				i += j;
				break;
			}
		}
		if (slovo_full == true) printf("����� ����������� � ������ � %d �� %d �������\n", i, i + len(slovo));
	}

	return 0;
}