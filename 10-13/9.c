#include<stdio.h>

void copy_vla(int, int, double ar1[*][*], double ar2[*][*]);
void print_vla(int, int, double ar[*][*]);

int main(void)
{
	double source[3][5] =
	{
		{11, 12, 13, 14, 15},
		{21, 22, 23, 24, 25},
		{31, 32, 33, 34, 35}
	};
	double target[3][5];

	copy_vla(3, 5, target, source);
	print_vla(3, 5, target);

	return 0;
}
void copy_vla(int line, int rank,
	double target[line][rank], double source[line][rank])
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; i < rank; ++j)
		{
			target[i][j] = source[i][j];
		}
	}
}
void print_vla(int line, int rank, double vla[line][rank])
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < rank; ++j)
		{
			printf("%.1lf\t", vla[i][j]);
		}
		printf("\n");
	}
}
