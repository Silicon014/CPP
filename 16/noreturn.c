#include<stdio.h>
#include<stdlib.h>

void hw(void)
{
	printf("hello, world\n");
}
_Noreturn void quit(void)
{
	void (* ptr)(void) = hw;
	atexit(ptr);
	exit(0);
}
int main(void)
{
	atexit(hw);
	quit();
	return 0;
}
