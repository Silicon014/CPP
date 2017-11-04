#include<stdio.h>
#include<stdlib.h>

int main(int argc, char * argv [])
{
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s file file1 file2 ...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	FILE * fp;
	if ((fp = fopen(argv[1], "a+")) == NULL)
	{
		fprintf(stderr, "Error: cannot open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (int i = 2; i < argc; ++i)
	{
		FILE * in;
		char ch;

		if ((in = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Error: cannot open file \"%s\"\n", argv[i]);	
			continue;
		}
		while ((ch = getc(in)) != EOF)
		{
			putc(ch, fp);
		}
		if (ferror(in))
		{
			fprintf(stderr, "Error while copying file \"%s\"\n", argv[i]);
			if (fclose(in) != 0)
			{
				fprintf(stderr, "Error when close file \"%s\"\n", argv[i]);
			}
			if (fclose(fp) != 0)
			{
				fprintf(stderr, "Error when close file \"%s\"\n", argv[1]);
				exit(EXIT_FAILURE);
			}
		}
		if (fclose(in) != 0)
		{
			fprintf(stderr, "Error when close file \"%s\"\n", argv[i]);
		}
	}
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error when close file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
	
