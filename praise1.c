/* praise1.c */
#include<stdio.h>
#define PRAISE "You are an extraordinary being."
int main(void)
{
	char name[40];

	printf("Whats your name? ");
	scanf("%s", name);
	printf("Hello, %s. %s\n",name, PRAISE);
	
	return 0;
}

