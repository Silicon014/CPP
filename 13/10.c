#include<stdio.h>
#include<stdlib.h>
#define LIM 64

char * s_gets(char word[], int limit);

int main(void)
{
	FILE * fp;

	printf("enter the fiilename:\n");
	
	char name[LIM];

	s_gets(name, LIM);
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "Error to open \"%s\"\n", name);
		exit(EXIT_FAILURE);
	}

	int place;
	
	printf("enter the place to begin (EOF to quit): ");
	while (scanf("%d", &place) != EOF)
	{
		
	
}	
	 
