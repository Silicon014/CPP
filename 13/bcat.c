#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv [])
{
	FILE * fp;
	const int SIZE = 1;
	char block[SIZE];
	
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", *argv);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr, "Error when open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fread(block, SIZE, 1, fp) == 1)
	{
		fwrite(block, SIZE, 1, stdout);
	}
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error when close file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
