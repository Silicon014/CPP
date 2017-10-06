#include<stdio.h>
#define y 2
#define x 5

void copy_ptr(double * , double * , int);

int main(void)
{
	double arr[y][x] = 
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0}
	};
	double target[y][x];

	for (int i = 0; i < y; ++i)
	{
		copy_ptr(target[i], arr[i], x);
		for (int j = 0; j < x; ++j)
		{
			printf("%g\t", target[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
void copy_ptr(double * target, double * source, int limit)
{
	for (int i = 0; i < limit; ++i)
	{
		*(target + i) = *(source + i);
	}
}
