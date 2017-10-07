#include<stdio.h>
#include<string.h>

void input(int line, int length, char ptr[][length]);
void output(int line, int length, char ptrs[line][length]);
int s_gets(char arr[], int);

int main(void)
{
	const int line = 5;
	const int length = 10;
	char arr[line][length];
	
	input(line, length, arr);
	
	for (int i = 1; i < line; ++i)
	{
		int j;
		char tmp[length];

		strcpy(tmp, arr[i]);
		for (j = i - 1; j >= 0 && strcmp(arr[j], arr[j + 1]) > 0; j--)
		{
			strcpy(arr[j + 1], arr[j]);
		}
		strncpy(arr[j + 1], tmp, length);
	}
	
	output(line, length, arr);
	
	return 0;
}
void input(int line, int length, char ptr[][length])
//控制输入
{
	for (int i = 0; i < line; ++i)
	{
		printf("Line %i (%i in total): ", i + 1, line);
		if (!s_gets(ptr[i], length))
			--i;
	}
}
int s_gets(char words[], int length)
{
	int i;

	fgets(words, length, stdin);
	for (i = 0; words[i] != '\n' && words[i] != '\0'; i++);
	if (words[i] == '\n')
		words[i] = '\0';
	else
		while (getchar() != '\n');
	return i - 1;
}
	
void output(int line, int length, char ptrs[line][length])
//控制输出
{
	for (int i = 0; i < line; ++i)
	{
		puts(ptrs[i]);
	}
}
