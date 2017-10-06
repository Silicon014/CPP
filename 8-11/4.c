#include<stdio.h>
#include<ctype.h>//提供isspace()、ispunct()

int main(void)
{
	const int IN = 1;
	const int OUT = 0;
	int ch;	//计数字母
	int wd;	//计数单词
	int state;
	char i;	//存储输入

	printf("Enter some sentences.\n");
	state = OUT;
	ch = 0;
	wd = 0;		//初始化
	while ((i = getchar()) != EOF)
	{
		if (isspace(i) || ispunct(i))
		{
			state = OUT;	//不是单词
		}
		else
		{
			if (state == OUT)
			{
				state = IN;	//开始新单词
				++wd;
			}
			++ch;
		}
	}
	printf("\nchar:%d\tword:%d\t\n", ch, wd);
	printf("average char of a word:%.1f\n",
		(float)ch / (float)wd);		//单词平均长度
	return 0;
}
