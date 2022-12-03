#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main()
{
	setlocale(LC_ALL, "Russian"); // русский €зык

	int n, st = 1;
	double s = 0, x;
	do {														// ввод данных(проверка "на дурака")
		printf("¬ведите число n: ");	scanf_s("%d", &n);
		printf("¬ведите число x: ");	scanf_s("%lf", &x);
	} while(n <= 1 || x <= 1);

	for(int i = 1; i <= n; i++)  // вычисл€ем сумму последовательности
	{
		if (i != 1)  s += 2 * log10(x);  // при i=1 сумма не увеличиваетс€ поэтому увечичиваем сумму когда i не равно 0 
	}
	printf("%.3lf", s); // вывод ответа

	return 1;
}