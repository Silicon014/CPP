/*配合toascii.c使用*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 40
#define LIM 5

int main(int argc, char * argv[])
{
	FILE * fp;
	char ch;
	char line[LEN];
	char word[LIM];

	//检查命令行参数
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	//打开文件
	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "Error: cannot open file\"%s\"\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	//输出
	while (fgets(line, LEN, fp) != NULL)
	{
		/*处理一行*/
		for (int i = 0; line[i] != '\n'; ++i)
		{//printf("%i\n", i);
			int j = 0;
			if (line[i] != '\t')
			{
				/*读入数字*/
				word[j] = line[i];
				++j;
			}
			else
			{
				/*跳过\t并刷新输出*/
				ch = atoi(word);
				fprintf(stdout, "%c", ch);
				/*复位*/
				j = 0;
				for (int i = 0; i < LIM; ++i)
				{
					word[i] = '\0';
				}
			}
		}
		/*行末尾*/
		putc('\n', stdout);
	}
}
