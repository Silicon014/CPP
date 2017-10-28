#include<stdio.h>
#include<stdlib.h>
int main(int argc, char * argv[])	//读取命令行参数
{
	FILE * fp;	// 文件指针

	if (argc < 2)	//检验命令行参数
	{
		/*报错并退出*/
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[1], "r")) == NULL)	//打开所指定的文件
	{
		/*处理错误*/
		fprintf(stderr, "Error when opening file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END);	//跳至文件末尾
	fprintf(stdout, "%ld\n", ftell(fp));	//报告字符总数
	if (fclose(fp) != 0)	//关闭文件
	{
		/*处理错误*/
		fprintf(stderr, "Error when closing file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return 0;
}
