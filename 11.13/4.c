#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
void getword(char [], int);
int main(void)
{
	const int N = 10;
	char arr[N];

	printf("Enter a word no longer than %i: ", N);
	getword(arr, N);
	printf("It's %s.\n", arr);	
	return 0;
}
void getword(char word[], int limit)
{
	char ch;
	int i;
	
	while(isspace(ch = getchar()));
	for (i = 0; i < limit && !isspace(ch); ++i)
	{
		word[i] = ch;
		ch = getchar();
	}
}
