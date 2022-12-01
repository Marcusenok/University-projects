#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main()
{
	// 13.	ƒано п€тизначное число. ќпределить число, полученное при перестановке в нем тыс€ч и сотен. 

	setlocale(LC_ALL, "Russian"); // русский €зык

	int chislo, sotni, tisachi, decatki_tisach, dectki, new_chislo;

	printf("¬ведите п€тизначное число: ");  scanf_s("%d", &chislo); // ввод данных
	 
	sotni = (chislo / 100) % 10; // количество сотен
	tisachi = (chislo / 1000) % 10; // количество тыс€ч
	decatki_tisach = chislo / 10000;
	dectki = chislo % 100;
	new_chislo = decatki_tisach * 10000 + sotni * 1000 + tisachi * 100 + dectki;
	
	printf("%d %d", chislo, new_chislo); // вывод

	return 0;
}

// 1234567
// 234