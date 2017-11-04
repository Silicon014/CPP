#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ifclear 1
int ctoi(char ch);
void clear(int line, int rank, int source[line][rank]);

int main(int argc, char * argv [])
{
	FILE * fp;
	int source[20][30];
	char ch;

	if (argc < 2)
	{
		fprintf(stderr, "cannot find a file to open\n");
		fprintf(stderr, "default: open file \"image\"\n");
		if ((fp = fopen("image", "r")) == NULL)
		{
			fprintf(stderr, "cannot open the file \"image\"\n");
			fprintf(stderr, "exit\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if ((fp = fopen(argv[1], "r")) == NULL)
		{
			fprintf(stderr, "cannot open the file \"%s\"\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 30;)
		{
			fscanf(fp, "%c", &ch);
			if (isdigit(ch))
			{
				source[i][j] = ctoi(ch);
				++j;
			}
		}
	}
	if (ifclear)
	{
		clear(20, 30, source);
	}

void clear(int line, int rank, source[line][rank])
{
	int a, b, c, d, x, y;

	for (int i = 0; i < line; ++i)
	{
		for (int j = 0; j < rank; ++j)
		{	
			if (i - 1 < 0)
				a = 0;
			else
				a = source[i - 1][j];
			if (j + 1 > rank)
				b = 0;
			else
				b = source[i][j + 1];
			if (i + 1 > line)
				c = 0;
			else
				c = source[c + 1][j];
			if (j - 1 < 0)
				d = 0;
			else
				d = source[i][j - 1];
			if (
			
			
			
			
				
int ctoi(char ch)
{
	switch (ch)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
}
				
