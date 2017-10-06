#include<stdio.h>

void getarr(int line, int rank, double arr[*][*]);
double aver_line(int rank, double arr[]);
double aver_total(int line, int rank, double arr[*][*]);
double max_arr(int line, int rank, double arr[*][*]);

int main(void)
{
	const int LINE = 3;
	const int RANK = 5;

	double ar[LINE][RANK];

	getarr(LINE, RANK, ar);
	for (int i = 0; i < LINE; ++i)
	{
		printf("Average of #%i: %.1lf\n", i + 1,
			aver_line(RANK, ar[i]));
	}
	printf("Average of total: %.1lf\n",
		aver_total(LINE, RANK, ar));
	printf("Max of total: %.1lf\n",
		max_arr(LINE, RANK, ar));
	return 0;
}
void getarr(int line, int rank, double arr[line][rank])
{
	for (int i = 0; i < line; ++i)
	{
		printf("Enter the nums of array #%i:\n", i + 1);
		for (int j = 0; j < rank; ++j)
		{
			printf("%i of %d: ", j + 1, rank);
			scanf("%lf", &arr[i][j]);
		}
	}
}
double aver_line(int limit, double arr[])
{
	double total = 0;

	for (int i = 0; i < limit; ++i)
	{
		total += arr[i];
	}
	return total / (double)limit;
}
double aver_total(int line, int rank, double arr[line][rank])
{
	double total = 0;

	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{
			total += arr[i][j];
		}
	}
	return total / (double)(line * rank);
}
double max_arr(int line, int rank, double arr[line][rank])
{
	double max = **arr;

	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{
			double tmp = arr[i][j];

			if (max < tmp)
			{
				max = tmp;
			}
		}
	}
	return max;
}
