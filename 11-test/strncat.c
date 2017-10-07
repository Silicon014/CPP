#include<stdio.h>
#include<string.h>

int main(void)
{
	char arr[12] = "hello, ";
	char * ptr = "world";

	puts(strncat(arr, ptr, sizeof(arr) - strlen(arr) - 1));
}
