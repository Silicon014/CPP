#include<stdio.h>
#include<stdlib.h>
void helloworld(void)
{
	printf("hello, world\n");
}
int main(void)
{
	void (* ptr)(void);

	ptr = helloworld;

	atexit(ptr);
	exit(0);
}
