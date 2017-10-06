#include<stdio.h>
#include<ctype.h>

int cwhere(char);

int main(void)
{
	const int NOTCHAR = -1;
	const int ONELINE = 8;
	char ch;
	int i = 0;	//计数打印数

	while ((ch = getchar()) != EOF)
	{
		if (cwhere(ch) != NOTCHAR)
		{
			printf("字母:%c%d  ",
				(cwhere(ch) < 10)?'0':'\0',
				cwhere(ch));
		}
		else
		{
			printf("非字母   ");
		}
		++i;
		if (!(i % ONELINE) || (ch == '\n'))
			putchar('\n');
	}
	putchar('\n');
	return 0;
}
int cwhere(char ch)
{
	int where;

	ch = toupper(ch);
	if (isupper(ch))
		where = ch - 64;
	else
		where = -1;
	return where;
}
