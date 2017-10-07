#include<stdio.h>

char * s_gets(char * , int);

int main(void)
{
	char arr[10];
	s_gets(arr, 10);
	puts(arr);
	return 0;
}
char * s_gets(char * words, int limit)
{
	char * ptr;
	ptr = fgets(words, limit, stdin);
	int i = 0;
	while (*(words + i) != '\n' && *(words + i) != '\0')
		++i;
	if (*(words + i) =='\n')
		*(words + i) = '\0';
	else
		while (getchar() != '\n')
			continue;
	return ptr;
}
