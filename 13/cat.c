#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv [])
{
	FILE * fp;
	const int LIM = 64;
	char line[LIM];

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", *argv);
		exit(EXIT_FAILURE);
	}
	
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error while open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while (fgets(line, LIM, fp) != NULL)
	{
		fputs(line, stdout);
		fflush(stdout);
	}
	
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error while close file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
