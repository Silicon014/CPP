#include<stdio.h>

int main(void)
{
	printf("Enter, use a # to stop.\n");
	
	int space = 0;
	int newline = 0;
	int others = 0;

	char c;

	while ((c = getchar()) != '#')
	{
		switch (c)
		{
			case '\n':
				++newline;
				break;
			case ' ':
				++space;
				break;
			default:
				++others;
				break;
		}
	}
	printf("End.\n");
	printf("Space:%d\nnewline:%d\nothers:%d\n",
		space, newline, others);
	return 0;
}
