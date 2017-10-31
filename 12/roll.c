#include<stdio.h>
#include<stdlib.h>
#include<time.h>							//提供time()的函数原型

#define FACE 6								//N面骰子

int main(int argc, char * argv [])
{
	int MAX;

	/*检查命令行参数*/
	if (argc != 2)
	{
		if (argc < 2)
		{
			fprintf(stderr, "Usage: %s num(int)\n", *argv);
			exit(EXIT_FAILURE);
		}
		else
		{
			fprintf(stderr, "Too more arguments\n");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		char * end;
		MAX = (int)strtol(argv[1], &end, 10);
		if (end == argv[1])
		{
			fprintf(stderr, "Usage: %s num(int)\n", *argv);
			exit(EXIT_FAILURE);
		}
	}

	srand((unsigned int)time(NULL));				//以时间函数返回伪随机数种子
	if (MAX == 0)
		fprintf(stderr, "Enter to roll, EOF to quit.\n");

	for (int i = 0; (MAX > 0)? (i < MAX): (getchar() != EOF); ++i)	//MAX == 0 时为手动
	{
		fprintf(stdout, "%d", rand() % FACE + 1);			//打印1～6间的随机数
		fflush(stdout);
	}
	fprintf(stderr, "\nDone.\n");

	return 0;
}	
