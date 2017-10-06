#include<stdio.h>

int main(void)
{
	const int NEWLINE = 8;
	char c = '\0';

	printf("Enter, use a # to end.\n");	
	for (int i = 0; c != '#'; ++i)
	{
		c = getchar();
		if (!(i % NEWLINE))
			putchar('\n');
		switch (c)
		{
			case '#':
				break;
			case '\n':
				printf("\\n %i\t", (int)c);
				i = -1;
				putchar('\n');
				break;
			case '\t':
				printf("\\t %i\t", (int)c);
				break;
			case ' ':
			printf("\\  %i\t", (int)c);
				break;
				default:
				printf("%c %i\t", c, (int)c);
				break;
		}
	}
	putchar('\n');
	return 0;
}
