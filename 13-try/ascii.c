#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	FILE *fp;
	char ch = 0;
	const int LIM = 127;

	if ((fp = fopen("alphabet", "w")) == NULL)
	{
		fprintf(stderr, "Error: cannot open file \"alphabet\"\n");
		exit(EXIT_FAILURE);
	}
	while (ch < LIM)
	{
		switch (ch)
		{
			case '\n':
				fprintf(fp, "%i:\t\\n\n", ch);
				break;
			case '\t':
				fprintf(fp, "%i:\t\\t\n", ch);
				break;
			case '\b':
				fprintf(fp, "%i:\t\\b\n", ch);
				break;
			default:
				fprintf(fp, "%i:\t%c\n", ch, ch);
				break;
		}
		++ch;
	}
	fprintf(fp, "%i:\t%c\n", LIM, LIM);
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error: cannot close file \"alphabet\"\n");
		exit(EXIT_FAILURE);
	}
	return 0;
}
