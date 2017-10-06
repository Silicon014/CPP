#include<stdio.h>

int main(void)
{
	const int LINE = 10;	//每行显示10项
	int ch;	//存储输入
	int i = 0;	//当前打印数，用于控制换行

	printf("Enter, use an EOF to end.\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch < (int)' ')
		{
			switch (ch)
			{
				case '\n':
					printf("\\n %d\t", ch);
					putchar('\n');
					i = 0;
					break;
				case '\t':
					printf("\\t %d\t", ch);
					break;
				default:
					printf("^%c %d\t", ch + 64, ch);
					break;
			}
		}
		else
			printf("%c %d\t", ch, ch);
		++i;
		if (i % LINE == 0)
			putchar('\n');
	}
	return 0;
}
