#include<stdio.h>
int main(int argc, char * argv [])
{
	if (argc < 2)
	{
		fprintf(stderr, "Error: please include at least one file\n");
		fprintf(stderr, "Usage: %s file1 file2 ...\n", *argv);
	}
	else
	{
		FILE * fp;
		for (int i = 1; i < argc; ++i)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Error: failed to open the file \"%s\"\n", argv[i]);
				break;
			}
			else
			{
				char ch;
				while ((ch = getc(fp)) != EOF)
				{
					putc(ch, stdout);
				}
				fflush(stdout);
			}
		}
	}
	return 0;
}
