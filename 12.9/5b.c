#include<stdio.h>
#define ALL 100

extern unsigned int rand1(void);
extern void set_sand(unsigned long int);
extern void sort_int(unsigned int [], int);
extern void qwq(unsigned int [], int);

unsigned int ar[ALL];
int main(void)
{
	unsigned long int seed;
	printf("set seed(0 to quit): ");
	scanf("%lu", &seed);
	while (getchar() != '\n');
	while (seed != 0)
	{
		set_sand(seed);
		for (int i = 0; i < ALL; ++i)
		{
			ar[i] = rand1() % 10 + 1;
		}
		sort_int(ar, ALL);
		for (int i = 0; i < ALL; ++i)
			printf("%u\n", ar[i]);
		printf("set seed(0 to quit): ");
		scanf("%lu", &seed);
		while (getchar() != '\n');
	}
	printf("Bye.\n");
	return 0;
}
/*bug*/
