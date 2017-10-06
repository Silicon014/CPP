#include<stdio.h>
#include<stdlib.h>//提供exit()函数

float taxd(float);//计算应交所得税
float scanner(void);//读取输入的数字
float overtime(float);//加班补偿
float salaryis(void);//读取选择的工资水平

int main(void)
{
	const float PERHOUR = salaryis();//每小时工资
	float worktime = overtime(scanner());
	/*读取数字，处理加班补偿，得到等效工时*/
	float salary = worktime * PERHOUR;//工资
	float tax = taxd(salary);//税

	printf("Total:%.1f\tTax:%.1f\tPure:%.1f\n",
		salary, tax, salary - tax);
	/*总收入，应交税，净收入*/
	return 0;
}
float overtime(float time)
{
	const int LIMIT = 40;//基本工作时间
	const float RATE = 1.5;//加班时间1.5倍处理

	if (time <= LIMIT)
		return time;//不作处理
	else
		return (time - LIMIT) * RATE + LIMIT;//超出部分以1.5倍计算
}
float taxd(float salary)
{
	const int BASIC = 300;//300以内交15%的税
	const int ADVANCED = 150;//300到450的部分交20%的税
	const float BASIC_TAXRATE = 0.15;
	const float ADVANCED_TAXRATE = 0.20;
	const float OVERFLOW_TAXRATE = 0.25;//超出部分交25%的税

	if (salary > BASIC + ADVANCED)
	{
		/*高于450的工资计算税率*/
		salary -= BASIC + ADVANCED;//得到超出部分
		return salary * OVERFLOW_TAXRATE//超出部分的税
			+ BASIC * BASIC_TAXRATE//300以内的税
			+ ADVANCED * ADVANCED_TAXRATE//300到450的税
			;
	}
	else
	{
		if (salary > BASIC)
		{
			/*300到450的工资计算税率*/
			salary -= BASIC;//得到超出部分
			return salary * ADVANCED_TAXRATE//300到450的税
				+ BASIC * BASIC_TAXRATE//300以内的税
				;
		}
		else
		{
			/*低于300的工资计算税率*/
			return salary * BASIC_TAXRATE;
		}
	}
}
float scanner(void)
{
	float hours;
	printf("How many hours do you work per week?\n");//询问每周工作时间
	while (!scanf("%f", &hours))
	{
		/*输入不是数字时*/
		printf("Wrong. Enter again.\n");//提醒
		while (getchar() != '\n')
			;			//处理错误输入的东西
	}
	while (getchar() != '\n')
		;		//处理多余的输入
	return hours;
}
void ask(void);//询问工资水平
float salaryis(void)
{
	const float S1 = 8.75,
		    S2 = 9.33,
		    S3 = 10.00,
		    S4 = 11.20;	//4种时薪以备选择
	float salary;		//薪水
	char ch;		//储存输入 

	do
	{
		ask();
		ch = getchar();
		while (getchar() != '\n')
			;		//处理多余的输入
		switch (ch)
		{
			case '1':
				salary = S1;
				break;
			case '2':
				salary = S2;
				break;
			case '3':
				salary = S3;
				break;
			case '4':
				salary = S4;
				break;
			case 'q':
			case '5':
				printf("Quit.\n");
				exit(0);
				break;			//退出程序
			default:
				printf("Error.\n");
				ch = '\0';
				break;			//提醒输入错误
		}
	}
	while (ch == '\0');
	return salary;
}
void starbar(void);//输出一行星星
void ask(void)
{
	starbar();
	printf("Enter the corresponding to "
		"the desired pay rate or action:\n");
					//看不懂，反正就那意思=。=
	printf("1) $8.75/hr\t\t");
	printf("2) $9.33/hr\n");
	printf("3) $10.00/hr\t\t");
	printf("4) $11.20/hr\n");
	printf("5) quit\n");
	/*五个选项*/
	starbar();
}
void starbar(void)
{
	const int STAR = 80;
	for (int i = 0; i < STAR; ++i)
		putchar('*');
}	
