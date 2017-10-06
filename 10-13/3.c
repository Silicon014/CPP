#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int max_intarr(int arr[], int);
int getint(void);

int main(void)
{
	const int max_num = 10;
	int arr[max_num];
	printf("Enter %i integers, or EOF to quit.\n", max_num);
	for (int i = 0; i < max_num; ++i)
	{
		printf("Enter an integer(%i of 10): ", i + 1);
		if ((arr[i] = getint()) == 0)
		{
			i--;
		}
	}
	printf("Complete.\n");
	printf("The max one is %d.\n", max_intarr(arr, max_num));
	return 0;
}

int max_intarr(int arr[], int limit)
{
	int max = *arr;
	for (int i = 0; i < limit; ++i)
	{
		max = (max > *(arr + i))? max: *(arr + i);
	}
	return max;
}
int getint(void)
/*从一次输入中按顺序获取所有的数字并返回此整数值*/
{
	char entered[12];	//存储输入
	char  scaned[12];	//存储数字字符

	if (scanf("%10s", entered) == EOF)	//输入上限为10个字符
	{
		/*EOF时退出*/
		printf("\nEnd of EOF.\n");
		exit(0);
	}
	for (int i = 0, a = 0; entered[i] != '\0'; ++i)
	/*依次获取输入的所有数字字符*/
	{
		if (isdigit(entered[i]))
		//若entered中的第i项是数字
		{
			scaned[a] = entered[i];	//把数字存入scaned
			++a;	//scaned的下一个元素
		}
	}
	return atoi(scaned);	//转化为整数并返回
}

/*
	10-4: bug，见log.3。
*/
