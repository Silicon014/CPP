#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 40

int main(int argc, char * argv[])
{
	FILE *in, *out;
	int ch;
	char name[LEN];
	int count = 0;
	
	//check commandline arguments
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//set input
	if ((in = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//set output
	strncpy(name, argv[1], LEN - 5);
	name[LEN - 5] = '\0';
	strcat(name, ".red");
	if ((out = fopen(name, "w")) == NULL )
	{
		fprintf(stderr, "Can't create output file.\n");
		exit(EXIT_FAILURE);
	}
	//copy data
	while ((ch = getc(in)) != EOF)
	{
		if (count++ % 3 == 0)
		{
			putc(ch, out);
		}
	}
	//all last
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files.\n");
	}
	
	return 0;
}
