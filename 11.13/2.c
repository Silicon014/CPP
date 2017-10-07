#include<stdio.h>
#include<ctype.h>

void get1(const int, char []);
int main(void)
{
	const int N = 10;
	char words[N];

	get1(N, words);
	puts(words);
	return 0;
}
void get1(const int n, char words[])
{
	int i;
	for (i = 0; i < n; ++i)
	{
		if (isspace(words[i] = getchar()))
			break;
	}
	if (i == n)
		words[--i] ='\0';
}
