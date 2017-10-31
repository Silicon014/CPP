#include<stdio.h>
#include<stdlib.h>	//提供exit()函数

int aline(FILE * a);	//从a中输出一行

int main(int argc, char * argv [])	/* 用法：./a.out file1 file2 */
{
	FILE * a, * b;
	int flagA, flagB;

	/*入口条件*/
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s file1 file2\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	/*加载文件*/
	if ((a = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: failed to open file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((b = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Error: failed to open file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	/*算法实现部分*/
	flagA = 1;
	flagB = 1;
	while (1)//用break语句退出循环
	{
		/*分别判断是否打印a，之后是否打印b，最后是否跳出循环*/
		if (flagA)
		{
			if (aline(a) == EOF)
				flagA = 0;	//设置flag
		}
		if (flagB)
		{
			if (aline(b) == EOF)
				flagB = 0;
		}
		if (!(flagA || flagB))
		{
			break;	//跳出循环
		}
	}
	/*退出*/
	if (fclose(a) != 0)
	{
		fprintf(stderr, "Error: failed to close file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fclose(b) != 0)
	{
		fprintf(stderr, "Error: failed to close file \"%s\"\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
int aline(FILE * fp)
/*读取并打印fp所指文件的一行；遇到文件结尾返回EOF，正常返回0*/
{
	char ch = getc(fp);

	while (ch != '\n' && ch != EOF)
	{
		putc(ch, stdout);
		ch = getc(fp);
	}
	if (ch == EOF)
	{
		return EOF;
	}
	else
	{
		putc('\n', stdout);
		return 0;
	}
}
