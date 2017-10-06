#include<stdio.h>
#include<ctype.h>	//提供islower()、isupper()

int main(void)
{
	char ch;	//存储输入
	int clower = 0,	//计数小写字母数量
	    cupper = 0;	//计数大写字母数量

	printf("Enter. EOF to end.\n");
	while ((ch = getchar()) != EOF)
	{
		clower += islower(ch)?1:0;
		cupper += isupper(ch)?1:0;
	}
	printf("\nYou entered %d lower char and %d upper char.\n",
		clower, cupper);
	return 0;
}
