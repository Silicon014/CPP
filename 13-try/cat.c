#include<stdio.h>
int main(int argc, char * argv[])	//命令行参数
{
	for (int i = 1; i < argc; ++i)
	{
		FILE * fp = fopen(argv[i], "r");	//打开第i个文件
		char ch;
		
		while ((ch = getc(fp)) != EOF)	//从文件中读一个字符
			putchar(ch);	//在读到EOF之前打印字符
	}
	return 0;
}
