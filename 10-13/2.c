#include<stdio.h>

void copy_arr(double arr1[], double arr2[], int limit_of_arr2);
void copy_ptr(double * , double * , int);
void copy_ptrs(double * , double * , const double * );

void printarr(double arr[], int);

int main(void)
{
	double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};

	double target1[5], target2[5], target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);

	printarr(target1, 5);
	printarr(target2, 5);
	printarr(target3, 5);

	return 0;
}

void copy_arr(double target[], double source[], int limit)
{
	for (int i = 0; i < limit; ++i)
	{
		target[i] = source[i];
	}
}
void copy_ptr(double * target, double * source, int limit)
{
	for (int i = 0; i < limit; ++i)
	{
		*(target + i) = *(source + i);
	}
}
void copy_ptrs(double * target, double * source, const double * overflow)
{
	int i = 0;
	while (source < overflow)
	{
		*(target + i) = *source;
		source++;
		++i;
	}
}
void printarr(double arr[], int limit)
{
	for (int i = 0; i < limit; ++i)
	{
		printf("%.1lf\t", arr[i]);
	}
	putchar('\n');
}
