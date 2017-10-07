#include<stdio.h>

int main(int argc, char * argv[])
{
	for (int i = 0; i < argc; i++)
	{
		puts(argv[i]);
	}
	printf("The argument count is %d.\n", argc);
	return 0;
}
