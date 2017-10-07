#include<stdio.h>

void put1(char * ptr);

void put1(char * ptr)
{
	while (*ptr)
		putchar(*ptr++);
}
