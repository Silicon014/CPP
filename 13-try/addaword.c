#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Error while open file wordy\n");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "Enter words to add to the file; press the #");
	fprintf(stdout, " key at the beginning of a line to terminate.\n");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
		fprintf(fp, "%s\n", words);
	puts("File contents:");
	rewind(fp);	//return where the file begins
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Done.");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error while closing wordy\n");
	return 0;
}
