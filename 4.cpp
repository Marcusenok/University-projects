#include <iostream>
#include <stdio.h>
// 4. ќпределить, сколько раз в тексте встречаетс€ заданное слово.


// функци€ дл€ определение длинны строки
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
	system("chcp 1251 > nul"); // дл€ работы с русским €зыком

	// объ€вление переменных
	char str[256];
	char slovo[100];
	bool slovo_full = true;
	printf("¬ведите строку: ");  gets_s(str);
	printf("¬ведите интересующее слово: ");  gets_s(slovo);

	// проверка на наличие слова в строке
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
		if (slovo_full == true) printf("—лово встречаетс€ в строке с %d по %d символы\n", i, i + len(slovo));
	}

	return 0;
}