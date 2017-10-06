#include<stdio.h>
int integer(void);

int main(void)
{
	int i = 0;
	int odd_num = 0,
	    even_num = 0;
	int odd_total = 0,
	    even_total = 0;

	while ((i = integer()) != 0)
	{
		if (i % 2)
		{
			++odd_num;
			odd_total += i;
		}
		else
		{
			++even_num;
			even_total += i;
		}
	}
	printf("odd: %d\taverage: %.2f\n", odd_num,
		(float)odd_total / (float)odd_num);
	printf("even:%d\taverage: %.2f\n", even_num,
		(float)even_total / (float)even_num);
	return 0;
}
int integer(void)
{
	int r;

	printf("Enter an integer (0 to stop): ");
	while (!scanf("%d", &r))
	{
		printf("Enter an integer (0 to stop): ");
		while(getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	return r;
}
