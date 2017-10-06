#include<stdio.h>
#define LIMIT 3

void add_2to1_arr(int limit, int source1[], int source2[], int target[]);

int main(void)
{
	int ar1[LIMIT] = {1, 2, 3};
	int ar2[LIMIT] = {4, 5, 6};
	int total[LIMIT];

	add_2to1_arr(LIMIT, ar1, ar2, total);
	for (int i = 0; i < LIMIT; ++i)
	{
		printf("%d\t", total[i]);
	}
	printf("\n");
	return 0;
}
void add_2to1_arr(int limit, int s1[], int s2[], int all[])
{
	for (int i = 0; i < limit; ++i)
	{
		all[i] = s1[i] + s2 [i];
	}
}
