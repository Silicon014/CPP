#include<stdio.h>
#include<stdlib.h>

double * readdouble(int num);

int main(int argc, char * argv [])
{
	FILE * fp;
	const int num = 10;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "w")) == NULL)
	{
		fprintf(stderr, "Error in open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fwrite(readdouble(num), sizeof(double), num, fp);
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error in close file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
double * readdouble(int num)
{
	double * arr = (double *) malloc(sizeof(double) * num);

	printf("Enter %i nums:\n", num);
	for (int i = 0; i < num; ++i)
	{
		printf("#%i: ", i + 1);
		if (fscanf(stdin,"%lf",arr + i) != 1)
		{
			printf("#%i: ", i + 1);
			--i;
		}
	}
	return arr;
}
