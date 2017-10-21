/*以ascii存储输入*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 40	//最大输入

int main(int argc, char * argv [])
{
	char line[LEN];	//存储输入
	FILE * fp;	//文件指针

	//检查命令行参数
	if (argc < 2)
	{
		/*处理错误情况*/
		fprintf(stderr, "Usage: %s filename\n", *argv);
		exit(EXIT_FAILURE);
	}
	//打开文件，模式为w（写）
	if ((fp = fopen(argv[1], "w")) == NULL)
	{
		/*处理错误情况*/
		fprintf(stderr, "Error: file \"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//提示并获取输入
	fprintf(stdout, "end with EOF.\n");
	while (fgets(line, LEN, stdin) != NULL)	
	{
		/*处理输入*/
		for (int i = 0; line[i] != '\0'; ++i)
		{
			/*转换为ascii*/
			if (line[i] != '\n')
			{
				fprintf(fp, "%i\t", line[i]);
			}
			else
			{
				/*不转换换行*/
				fprintf(fp, "%c", line[i]);
			}
		}
	}
	//结束
	printf("End.\n");
	exit(EXIT_SUCCESS);
}
/*注意会清空原文件，不要以此程序打开已存在的文件。*/
