//compile with 3a.c
#include<stdio.h>
#include<ctype.h>

void s_gets(char * word, int max)
{
	fgets(word, max, stdin);
	int i;
	for (i = 0; word[i] != '\n' && word[i] != '\0'; ++i)
	{
		continue;
	}
	if (word[i] == '\n')
	{
		word[i] = '\0';
	}
}
void uppercp(FILE * in, FILE * out)
{
	char ch;
	while ((ch = getc(in)) != EOF)
	{
		putc(toupper(ch), out);
	}
}
