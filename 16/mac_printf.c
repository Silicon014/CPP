#include<stdio.h>
#define PRINTF(X, ...) printf(X, __VA_ARGS__)
int main(void)
{
	PRINTF("%s, %s\n", "hello", "world");
	return 0;
}
