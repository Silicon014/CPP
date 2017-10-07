#include<stdio.h>

int main(void)
{
	char arr[6];
	printf("This is fgets:\n");
	fgets(arr, 6, stdin);
	printf("fgets read:\n");
	printf("%s", arr);
	printf("\tEnd.\n");
	return 0;
}
