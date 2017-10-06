#include<stdio.h>	//提供getchar()、printf()
#include<stdlib.h>	//提供exit()
#include<ctype.h>	//提供tolower()
#define LO 1
#define HI 100

void quit(void);
void illus(void);

int main(void)
{
	int i = 1;	//标识程序的运行状态
	char ch;	//存储输入
	int upper = HI;
	int lower = LO;
	int guess;

	illus();	//打印说明
	while (i)
	{
		do
		{
			/*询问是否开始或退出*/
			ch = getchar();
			while (getchar() != '\n')
				continue;
			switch (ch)
			{
				case 's':
				case 'S':
					printf("Start.\n");
					i = 1;
					break;
				case 'q':
				case 'Q':
					i = 0;
					quit();	//询问是否退出
					break;
				default:
					printf("s or q.\n");
					i = 0;
					break;
			}
		}
		while (!i);
		do
		{
			guess = (upper - lower) / 2 + lower;
			printf("%d?\t", guess);
			do
			{
				ch = getchar();
				while (getchar() != '\n')
					continue;
				switch (tolower(ch))
				{
					case 'q':
						i = 0;
						quit();	//询问是否退出
						break;
					case 'u':
						i = 1;
						upper = guess - 1;
						break;
					case 'd':
						i = 1;
						lower = guess + 1;
						break;
					case 'y':
						i = 2;
						break;
					default:
						printf("q, u, d or y.\n");
						i = 0;
						break;
				}
			}
			while (!i);
		}
		while (i == 1);
		printf("Thus the number is %d.\n", guess);
		printf("s to restart. q to quit.\n");
	}
	return 0;
}
void quit(void)
{
	printf("Quit? y/n: ");
	if (getchar() == 'y')
	{
		printf("quit.\n");
		exit(0);
	}
	else
	{
		while (getchar() != '\n')
			continue;
		printf("Not quit.\n");
	}
}
void illus(void)
{
	printf("Num guessing\n");
	printf("Issue a num 1 to 100 in your heart.\n");
	printf("If the given num is higher than yours,\n");
	printf("please enter u; if lower, enter d.\n");
	printf("Of cause, if the num is right, enter y.\n");
	printf("Always enter q if you want to quit.\n");
	printf("If you are ready, enter s to start.\n");
}
