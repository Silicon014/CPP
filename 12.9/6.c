#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	const int total = 1000;
	const int num = 10;
	int rank[num];
	int a = 0;
	puts("Enter a seed(EOF to quit): ");
	while (scanf("%d", &a) != EOF)
	{
		srand(a);
		for (a = 0; a < num; ++a)
		{
			rank[a] = 0;
		}
		for (a = 0; a < total; ++a)
		{
			int i = rand() % num;
			++rank[i];
		}
		for (a = 0; a < num; ++a)
		{
			printf("%i:\t%d\n", a + 1, rank[a]);
		}
	}
	puts("Bye.");
	return 0;
}
