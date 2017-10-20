#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	FILE * ptr = fopen(".tmp.log", "w");
	char ch;
	int i = 0;

	puts("typing, use a # to end.");
	while ((ch = getc(stdin)) != '#')
	{
		putc(ch, ptr);
	}
	fclose(ptr);
	ptr = fopen("tmp", "r");
	while ((ch = getc(ptr)) != EOF)
	{
		switch (ch)
		{
			case '\n':
				printf("\\n\t");
				break;
			case '\t':
				printf("\\t\t");
				break;
			case ' ':
				printf("\\ \t");
				break;
			default:
				printf("%c\t", ch);
				break;
		}
		i++;
		if (!(i / 8))
		{
			putc('\n', stdout);
		}
	}
	putc('\n', stdout);
	fclose(ptr);
	return 0;
}
