#include<stdio.h>

int main(void)
{
	char ch1, ch2;
	int i;

	ch1 = ch2 = '\0';
	printf("Typing. I will count all \"ei\"s.\n\
Always end with a #.\n");
	while ((ch1 = getchar()) != '#')
	{
		if (ch1 == 'i' && ch2 == 'e')
			++i;
		ch2 = ch1;
	}
	printf("There are %d \"ei\".\n", i);
	return 0;
}
