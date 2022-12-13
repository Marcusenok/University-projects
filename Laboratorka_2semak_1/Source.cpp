#include <iostream>


// 4.	Даны	координаты	трех вершин	треугольника.Вычислить длины всех его сторон и площадь, если треугольник существует.


int main()
{
	system("chcp 1251 > nul");

	double ax, ay, bx, by, cx, cy, ab, bc, ca, *a, *b, *c;

	printf("A: x = "); scanf_s("%lf", &ax); printf("A: y = "); scanf_s("%lf", &ay);
	printf("B: x = "); scanf_s("%lf", &bx); printf("B: y = "); scanf_s("%lf", &by);
	printf("C: x = "); scanf_s("%lf", &cx); printf("C: y = "); scanf_s("%lf", &cy);

	printf("%.2lf %.2lf %.2lf %.2lf %.2lf %.2lf\n", ax, bx, cx, ay, by, cy);

	ab = sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
	bc = sqrt(pow((bx - cx), 2) + pow((by - cy), 2));
	ca = sqrt(pow((cx - ax), 2) + pow((cy - ay), 2));

	c = &ab;
	a = &bc;
	b = &ca;

	if (((*a + *b) > *c) && ((*a + *c) > *b) && ((*b + *c) > *a) && (*a > 0) && (*b > 0) && (*c > 0))
	{
		printf("Треугольник существует\n");
		printf("AB = %lf\n", *c);
		printf("BC = %lf\n", *a);
		printf("CA = %lf\n", *b);
		double p = ((*c + *a + *b) / 2);
		double plohcad = sqrt(p * (p - *c) * (p - *a) * (p - *b));
		printf("P = %lf", plohcad);
	}
	else printf("Треугольника не существует");

	return 0;
}