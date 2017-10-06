#include<stdio.h>
#define HW "hello, world\n"
int main(void)
{
	const char * ptr = HW;
	printf("%s", ptr);
	return 0;
}
