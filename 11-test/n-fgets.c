#include<stdio.h>

int main(void)
{
	const int STLEN = 10;
	char words[STLEN];
	int count = 0;
	int i;

	printf("EOF to quit.\n");
	while (fgets(words, STLEN, stdin) != NULL)
	{
		for (i = 0; words[i] != '\0' && words[i] != '\n';  ++i)
			continue;
		if (words[i] == '\n')
			words[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
		count += puts(words) - 1;
	}
	printf("%d chars typed.\n", count);
	return 0;
}
