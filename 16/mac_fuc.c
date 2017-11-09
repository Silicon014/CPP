#include<stdio.h>
#define X(x) x*x
#define AX(x) x*x+2
#define PRINT(x) printf("%d\n", x)
int main(void)
{
	int a = X(4);
	int b = AX(4);

	PRINT(a);
	PRINT(b);
	return 0;
}

