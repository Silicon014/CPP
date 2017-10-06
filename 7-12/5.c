#include<stdio.h>

int main(void)
{
	char ch;

	printf("Enter, use a # to end.\n");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
			case '!':
				printf("!!");
				break;
			case '.':
				printf("!");
				break;
			default:
				printf("%c", ch);
				break;
		}
	}
	printf("\nEnd.\n");
	return 0;
}
