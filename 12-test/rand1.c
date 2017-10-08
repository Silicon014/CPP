#include<stdio.h>

extern unsigned int rand0(void);

int main(void)
{
	puts("emmm....");
	const int N = 5;
	for (int i = 0; i < N; ++i)
	{
		printf("%u\n", rand0());
	}
	return 0;
}
