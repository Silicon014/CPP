#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 20

int main(int argc, char *argv [])
{
	FILE *in, *out;
	char ch;
	char name[LEN];
	const int ADD = 10;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//input file
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error in opening: filename:%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//output file
		/*preperation*/
	strncpy(name, argv[1], LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name, ".add");
		/*end*/
	if ((out = fopen(name, "w")) == NULL)
	{
		fprintf(stderr, "Error in opening: filename:%s\n", name);
		exit(EXIT_FAILURE);
	}
	//copy
	while ((ch = getc(in)) != EOF)
	{
		putc(ch + ADD, out);
	}
	//end
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files.\n");
	}
	return 0;
}
