/*	1.负幂
	2.0的任何次幂为0
	3.任何数的0次幂为1
	4.报告0的0次幂未定义，并把该值处理为1
*/
#include<stdio.h>

double power(double, int);

int main(void)
{
	double x, xpow;
	int exp;

		/*介绍*/
	printf("Enter a number and the positive integer power");
	printf(" to which \nthe number will be raised. Enter q");
	printf(" to quit.\n");
		/*获取输入*/
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		/*scanf()得到两个输入时正常进入循环*/
		xpow = power(x, exp);	//计算xpow
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
		/*其他情况退出*/
	printf("Hope you enjoyed this power trip -- bye!\n");
	return 0;
}
double power(double x, int exp)
{
	if (x == 0.0)
	{
		if (exp == 0)
		{
			printf("0 to the power 0 is unknown."
				" 1 is defined.\n");
			return 1.0;	//0的0次方为1
		}
		else
		{
			return 0.0;	//0的非0次方为0
		}
	}
	else
	{
		if (exp == 0)
			return 1;
		else
			return x * power(x, exp - 1);
	}
}
