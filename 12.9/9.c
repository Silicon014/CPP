#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define SIZE 20

char * word(void)
{
	char * ptr = malloc(SIZE);
	char ch;
	int i = 0;

	while (isspace(ch = getchar()));
	do
	{
		*(ptr + i++) = ch;
	}
	while (!isspace(ch = getchar()));
	*(ptr + i) = '\0';
	return ptr;
}
int main(void)
{
	int n = 0;

	printf("How many words do you wish to enter? ");
	while (scanf("%d", &n) != EOF && n != 0)
	{
		char * arr[n];
		printf("Enter %d words now:\n", n);
		for (int i = 0; i < n; ++i)
		{
			arr[i] = word();
		}
		puts("Here are your words:");
		for (int i = 0; i < n; ++i)
		{
			printf("%s\n", arr[i]);
			free(arr[i]);
		}
		printf("How many words do you wish to enter?(0 to quit) ");
	}
	puts("\nBye.");
	return 0;
}
