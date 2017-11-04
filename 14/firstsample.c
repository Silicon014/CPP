#include<stdio.h>

#define NAMELEN 64
#define AUTLEN 64

struct book
{
	char name[NAMELEN];
	char author[AUTLEN];
	double price;
};

char * s_gets();

int main(void)
{
	struct book lib;

	fprintf(stdout, "Enter the bookname: ");
	fflush(stdout);
	s_gets(lib.name, NAMELEN);
	fprintf(stdout, "Enter the author: ");
	fflush(stdout);
	s_gets(lib.author, AUTLEN);
	fprintf(stdout, "Enter the price: ");
	fflush(stdout);
	fscanf(stdin, "%lf", &lib.price);
	
	printf("Bookname: %s\n", lib.name);
	printf("Author: %s\n", lib.author);
	printf("Price: %.2lf\n", lib.price);

	return 0;
}
char * s_gets(char * ptr, int lim)
{
	char * rtn;
	int i;
	
	rtn = fgets(ptr, lim, stdin);
	for (i = 0; *(ptr + i) != '\n' && *(ptr + i) != '\0';++i);
	if (*(ptr + i) == '\n')
	{
		*(ptr + i) = '\0';
	}
	return rtn;
}
