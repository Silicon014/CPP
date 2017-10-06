/*猜数字*/
#include<stdio.h>

int main(void)
{
	const int STAR = 80;
	int all = 0;	//猜测次数
	char ch;	//存储输入
	int i;		//辅助判断

	for (int i = 0; i < STAR; ++i)
	{
		putchar('*');
	}
	putchar('\n');			//输出一行星号
	printf("————猜数字————\n");
	printf("从1到100中选择一个数字\n");
	printf("若猜测数字大于你选择的数字，输入u\n");
	printf("若小于选择的数字，输入d\n");
	printf("猜对的话，输入y。\n");
	printf("输入s开始,输入q退出: ");
	while (')
	{
		printf("请输入s开始: ");
		while (getchar() != '\n')
			;		//处理错误输入
	}
	while (getchar() != '\n')
		;			//处理多余输入
	int upper = 100;
	int lower = 1;
	int guess;
	while (i)
	{
		guess = lower + (upper - lower) / 2;
		printf("%d? ", guess);
		do
		{
			ch = getchar();
			switch (ch)
			{
				case 'u':
					upper = guess - 1;
					break;
				case 'd':
					lower = guess + 1;
					break;
				case 'y':
					i = 0;
					break;
				default:
					ch ='\0';
					printf("错误。重新输入: ");
					break;
			}
		}
		while (ch == '\0');
	}
	printf("
