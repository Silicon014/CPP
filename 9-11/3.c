#include<stdio.h>
#include<ctype.h>	//提供isspace()

void chline(char, int, int);

int main(void)
{
	char ch;
	int a, b;

	printf("输入行数: ");
	while (!scanf("%d", &b))
	{
		/*输入非数字时*/
		printf("输入行数: ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	printf("输入列数: ");
	while (!scanf("%d", &a))
	{
		printf("输入列数: ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	printf("输入待打印的字符: ");
	ch = getchar();
	while (isspace(ch))
	{
		/*当字符为空白时*/
		printf("输入待打印的字符: ");
		if (!(ch =='\n'))	//存在多余输入时
		{
			while (getchar() != '\n')
				continue;
		}
		ch = getchar();
	}
	while (getchar() != '\n')
		continue;
	printf("%c: 行:%d 列:%d\n", ch, b, a);
	chline(ch, a, b);
	return 0;
}
void chline(char c, int x, int y)
{
	for (int i = 0; i < y; ++i)
	{
		for (int i = 0; i < x; ++i)
		{
			putchar(c);
		}
		putchar('\n');
	}
	putchar('\n');
}
