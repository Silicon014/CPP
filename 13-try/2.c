#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 40

int main(void)
{
	FILE * fp;
	char words[MAX];
	int num;

	if ((fp = fopen(".wordy", "a+")) == NULL)
	{
		printf("Failed to open the file \".wordy\".\n");
		exit(EXIT_FAILURE);
	}
	
	puts("Enter words to add to the file. EOF to end.");
	while (fscanf(stdin, "%40s", words) != EOF)
	{
		fprintf(fp, "%s\n", words);
	}
	fprintf(stdout, "File contents:\n");
	rewind(fp);
	while (fscanf(fp, "%s", words) == 1)
	{
		puts(words);
	}
	puts("Done.");
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "Error closing file\n");
	}

	return 0;
}
