#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	const int total = 100;
	int rank[total];
	int a = 0;
	for (int i = 0; i < total; i++)
	{
		int j;
		int tmp = rank[i] = rand() % 10 + 1;

		for (j = i - 1; j >= 0 && rank[j] > tmp; j--)
		{
			rank[j + 1] = rank[j];
		}
		rank[j + 1] = tmp;
	}
	for (int i = 0; i < total; ++i)
	{
		printf("%d\t", rank[i]);
		++a;
		if (!(a % 8))
		{
			putchar('\n');
		}
	}
	putchar('\n');
	return 0;
}
		
