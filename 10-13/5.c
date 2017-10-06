#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
double get_double(void);
double min_max(double arr[], int);
int main(void)
{
	const int max_arr = 5;
	double arr[max_arr];

	printf("Enter %i nums, or EOF to quit.\n", max_arr);
	for (int i = 0; i < max_arr; ++i)
	{
		printf("Enter a num (%i of %i): ", i + 1, max_arr);
		if ((arr[i] = get_double()) == 0)
		{
			i--;
		}
	}
	printf("%.1lf.\n", min_max(arr, max_arr));
	return 0;
}
double get_double(void)
{
	char entered[32];
	char scaned[32];
	
	if (scanf("%30s", entered) == EOF)
	{
		printf("\nEnd of EOF.\n");
		exit(0);
	}
	for (int i = 0, a = 0; entered[i] != '\0'; ++i)
	{
		if (entered[i] == '.' || isdigit(entered[i]))
		{
			scaned[a] = entered[i];
			++a;
		}
	}
	return atof(scaned);
}
double min_max(double arr[], int limit)
{
	int max = 0;
	int min = 0;

	for (int i = 0; i < limit; ++i)
	{
		max = (arr[max] > arr[i])? max: i;
		min = (arr[min] < arr[i])? min: i;
	}
	return arr[max] - arr[min];
}
