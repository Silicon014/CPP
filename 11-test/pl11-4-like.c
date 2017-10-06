#include<stdio.h>

int main(void)
{
	char *pointers[2] = 
	{
		"hello, ",
		"world\n",
	};
	char array[2][8] =
	{
		"hello, ",
		"world\n",
	};
	for (int i = 0; i < 2; ++i)
	{
		printf("%s", *(pointers + i));
	}
	for (int i = 0; i < 2; ++i)
	{
		printf("%s", array[i]);
	}
	printf("%zd\n", sizeof(pointers));
	printf("%zd\n", sizeof(array));
	return 0;
}
