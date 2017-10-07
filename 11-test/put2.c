#include<stdio.h>

int put2(char * ptr);

int put2(char * ptr)
{
	int i = 0;
	while (*ptr)
	{
		putchar(*ptr);
		++i;
	}
	putchar('\n');
	return i;
}
