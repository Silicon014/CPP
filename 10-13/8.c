#include<stdio.h>

void copy_ptrs(double * , double * , double * );

int main(void)
{
	double source[7] = {1, 2, 3, 4, 5, 6, 7};
	double target[3];

	copy_ptrs(target, source + 2, source + 5);
	for (int i = 0; i < 3; ++i)
		printf("%.1lf\t", *(target + i));
	putchar('\n');
	return 0;
}
void copy_ptrs(double * target, double * source, double * overflow)
{
	for (int i = 0;source + i < overflow; i++)
		*(target + i) = *(source + i);
}
