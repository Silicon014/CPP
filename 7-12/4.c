#include<stdio.h>

int main(void)
{
	char c;
	
	while ((c = getchar()) != '#')
	{
		if (c == '!')
			printf("!!");
		else
		{
			if (c == '.')
				printf("!");
			else
				printf("%c", c);
		}
	}
	putchar('\n');
	return 0;
}
