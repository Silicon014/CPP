#include<stdio.h>
#include<stdlib.h>
#define WORD "hello, world"

int main(int argc, char * argv [])	/*用法：./a.out filename lines (text of line) */
{
	FILE * fp;	//打开一个文件
	char * text = WORD;	//每行的文本

	int line;	//行数
	char * tmp;	//用于strtol()函数和之后的比对

	/*入口条件*/
	if (argc < 3)
	{
		fprintf(stderr, "Usage: %s filename lines\n", *argv);
		exit(EXIT_FAILURE);
	}
	/*初始化*/
	if ((fp = fopen(argv[1], "wx")) == NULL)	//以wx模式创建文件
	{
		fprintf(stderr, "failed to open file \"%s\": file is already exists\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = (int)strtol(argv[2], &tmp, 10);	//读取行数
	if (tmp == argv[2])
	/*判断行数信息是否正确*/	
	{
		fprintf(stderr, "\"lines\" means a number of lines.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		fprintf(stdout, "lines: %d\n", line);	//用户验证行数信息
		fflush(stdout);	//刷新输出
	}
	if (argc > 3)
	{
		text = argv[3];	//自定义每行的文字
	}
	/*写文件*/
	for (int i = 0; i < line; ++i)
	{
		fputs(text, fp);
		putc('\n', fp);	//行末尾
	}
	/*退出*/
	if (fclose(fp) != 0)
	{
		fprintf(stderr, "failed to close file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
