#include <stdio.h>
#include <math.h>
int main()
{
	int st1, i;
	double s = 0, x, stx, tosnost, sl, f;
	scanf("%lf%lf", &x, &tosnost);
	st1 = -1;
	f = 1;
	stx = x;
	i = 1;
	do
	{
		sl = st1 * stx / f;
		s += sl;
		i++;
		stx *= x;
		st1 *= -1;
		f *= i;
	} while (fabs(sl) > tosnost);
	printf("%lf", s);

	return 1;
}
