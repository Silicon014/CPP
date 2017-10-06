#include<stdio.h>
#define TIMES 2
void multiple_arr(int time, int limit1, int limit2, int arr[*][*]);
int main(void)
{
	int arr[3][5] = 
	{
		{1, 2, 3, 4, 5},
		{6, 7, 8, 9, 0},
		{10, 11, 12, 13, 14}
	};

	multiple_arr(TIMES, 3, 5, arr); 
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void multiple_arr(int times, int line, int rank, int arr[line][rank])
{
	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{
			arr[i][j] *= times;
		}
	}
}
