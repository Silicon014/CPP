#include<stdio.h>
#include<stdlib.h>//提供exit（）函数

int main(int argc, char * argv [])
{
	FILE * in, * out;//文件指针
	char ch;//存储

	if (argc < 3)//检查命令行参数
	{
		//处理可能的错误
		fprintf(stderr, "Usage: %s file1 file2\n", *argv);
		exit(EXIT_FAILURE);
	}
	if ((in = fopen(argv[1], "rb")) == NULL)//打开file1
	{
		//处理可能的错误
		fprintf(stderr, "Error: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if ((out = fopen(argv[2], "wb")) == NULL)//打开file2
	{
		//处理可能的错误
		fprintf(stderr, "Error: %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}

	while (fread(&ch, sizeof(char), 1, in) == 1)//从file1中读取一个字节
	{
		if (fwrite(&ch, sizeof(char), 1, out) != 1)//向file2中写入一个字节
		{
			//处理可能的错误
			fprintf(stderr, "Error in writing\n");
			exit(EXIT_FAILURE);
		}
	}
	
	if (fclose(in) != 0)//关闭file1
	{
		//处理可能的错误
		fprintf(stderr, "Error in closing file:%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (fclose(out) != 0)//关闭file2
	{
		//处理可能的错误
		fprintf(stderr, "Error in closing file:%s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);//退出程序
}
