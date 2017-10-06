#include<stdio.h>

void order_of(double * a, double * b, double * c);
void exchange(double * x, double * y);

int main(void)
{
	double x, y, z;

	scanf("%lf, %lf, %lf", &x, &y, &z);
	order_of(&x, &y, &z);
	printf("%lf, %lf, %lf\n", x, y, z);
	return 0;
}
void order_of(double * x, double * y, double * z)
{
	if (*x <= *y && *y <= *z)
		;
	else
	{
		if (*x <= *y && *y > *z)
		{
			if (*x <= *z)
			{
				exchange(y, z);
			}
			else
			{
				exchange(y, z);
				exchange(x, y);
			}
		}
		else
		{
			if (*x > *y && *y <= *z)
			{
				if (*x > *z)
				{
					exchange(x, y);
					exchange(y, z);
				}
				else
				{
					exchange(x, y);
				}
			}
			else
			{
				exchange(x, z);
			}
		}
	}
}
void exchange(double * a, double * b)
{
	double i;

	i = *a;
	*a = *b;
	*b = i;
}
