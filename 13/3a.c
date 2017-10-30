//compile with 3b.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 64

extern void s_gets(char *, int);
extern void uppercp(FILE * in, FILE * out);

int main(void)
{
	FILE * in, * out;
	char name[LEN];
	char * add = ".upper";

	puts("Enter the name of file:");
	s_gets(name, LEN - strlen(add));
	
	if ((in = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Error while opening file:%s\n", name);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(strcat(name, add), "w")) == NULL)
	{
		fprintf(stderr, "Error while creating *%s\n", add);
		exit(EXIT_FAILURE);
	}
	uppercp(in, out);
	if (fclose(in) != 0 || fclose(out) != 0)
	{
		fprintf(stderr, "Error in closing files");
		exit(EXIT_FAILURE);
	}
	puts("Done.");
	return 0;
}
	
