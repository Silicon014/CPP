#include<stdio.h>
void primenum(int);

int main(void)
{
	unsigned int upper;//需要输入一个正整数
	printf("Enter the upper limit: ");//提示输入数字作为上限
	while (!scanf("%u", &upper))
	{
		/*输入错误时*/
		printf("Only unsigned integer please.\n");//报错
		printf("Enter again: ");//提示再次输入
		while (getchar() != '\n')
			;		//处理错误输入
	}
	while (getchar() != '\n')
		;	//处理多余输入
	primenum((int)upper);//交由primenum()函数处理
	return 0;
}
void primenum(int upper)
{
//	printf("primenum() start with num %d.\n", upper);
	/*输出所有小于upper的素数*/
	const int lower = 2;//从2开始
	int primes[upper - lower];//primes[]用于存储所有upper到lower之间的数

	for (int i = 0; i < upper - lower; ++i)
		primes[i] = lower + i;		//初始化数组,从小到大排列
	for (int i = 0; i < upper - lower; ++i)
	{
		if (primes[i] != 0)
		{
//			printf("For num %d:\n", primes[i]);
			/*划去所有primes[i]的倍数*/
			for (int a = 1; a < upper - lower - i; ++a)
			{
				if ((primes[i + a] % primes[i] == 0)
					&& (primes[i + a] != 0))
				{
//					printf("covered:%d\n",
//						primes[i + a]);
					primes[i + a] = 0;
				}
			}
		}
	}

	const int LINE = 8;//每行显示8个数
	int a = 0;//计数当前打印的数的个数

	printf("Prime numbers under %d:\n", upper);
	for (int i = 0; i < upper - lower; ++i)
	{
		/*打印所有primes[]中的非零值*/
		if (primes[i] != 0)
		{
			printf("%d\t", primes[i]);
			++a;
			if (a % LINE == 0)
				putchar('\n');	//换行
		}
	}
	putchar('\n');
}
