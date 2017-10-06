#include<stdio.h>

double min(double, double);	//min()的函数原型

int main(void)
{
	/*比较两个数字的大小，并给出较小的数字*/
	double x, y;
	
	printf("输入两个数字:\n");
	/*获取第一个数字*/
	printf("1) ");
	while (!scanf("%lf", &x))
	{
		/*当输入非数字时*/
		printf("1) ");
		while (getchar() != '\n')
			continue;	//处理错误输入的部分
	}
	while (getchar() != '\n')
		continue;	//处理多余的输入部分
	/*同理，获取第二个数字*/
	printf("2) ");
	while (!scanf("%lf", &y))
	{
		printf("2) ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	/*计算并输出答案*/
	printf("较小的数字是%.2lf.\n",
		min(x, y));
	return 0;
}
double min(double a, double b)
{
	/*返回二者中较小的数*/
	if (a > b)
		return b;
	else
		return a;
}
