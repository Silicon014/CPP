#include<stdio.h>

double harmomean(double, double);
double getdouble(int);

int main(void)
{
	double x, y;

	printf("调和平均数\n");
	printf("输入两个数:\n");
	x = getdouble(1);
	y = getdouble(2);
	printf("两数的调和平均数为%.2lf.\n",
		harmomean(x, y));
	return 0;
}
double harmomean(double x, double y)
{
	double a = 1.0 / x;
	double b = 1.0 / y;

	a = (a + b) / 2.0;
	b = 1.0 / a;
	return b;
}
double getdouble(int i)
{
	double a;

	printf("%i): ", i);
	while (!scanf("%lf", &a))
	{
		printf("%i): ", i);
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
}
