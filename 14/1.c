#include<stdio.h>
#include<stdlib.h>
#include<string.h>//提供strcpy()、strcmp()
struct month {
	/*该月信息*/
	int number;//月编号（1到12）
	int days;//本月天数
	char fullname[15];//英文全名
	char abbr[5];//英文缩写
	};
void prime(struct month months []);//初始化每月信息
int main(void)
{
	int year, date, monmode;
	/*年，日。monmode为输入月份形式的标记。支持数字、英文缩写和英文全称。*/
	char mon[15];	//存储输入的月份。
	struct month months[12];//创建12个month结构，存储1到12月的信息以供查询

	printf("输入当前年、月、日：\n");
	printf("年份：");
	/*获取年份输入*/
	while (scanf("%d", &year) != 1)
	{	
		/*处理错误*/
		printf("未读取到年份。请重新输入。\n");
		printf("年份：");
		while (getchar() != '\n')//清空输入
			continue;
	}
	while (getchar() != '\n')//清空输入
		continue;
	printf("月份：");
	/*获取月份输入*/
	scanf("%15s", mon);
	while (getchar() != '\n')
		continue;
	printf("日期：");
	/*获取日期输入*/
	while (scanf("%d", &date) != 1)
	{
		/*处理错误*/
		printf("未读取到日期。请重新输入。\n");
		printf("日期：");
		while (getchar() != '\n')//清空输入
			continue;
	}
	while (getchar() != '\n')//清空输入
		continue;
	/*初始化各月资料*/
	prime(months);
	if (!(year % 4))
	{
		months[1].days++;//处理闰年
	}
	/*得到月份的输入形式（以长度判断）*/
	monmode = strlen(mon);
	/*搜索相匹配的月份资料*/
	for (int i = 0; i < 12; ++i)
	{
		switch (monmode)//数字、缩写、全名
		{
			case 1:
			case 2:
				if (months[i].number == atoi(mon))//比较数字
				{
					monmode = 0;//借用monmode
					for (int j = 0; j < i; ++j)//所有之前月份天数之和
					{
						monmode += months[j].days;
					}
					printf("今年已经过去了%d天。\n", monmode + date);
					return 0;//退出程序
				}
				break;
			case 4:
				if (strcmp(months[i].abbr, mon) == 0)//比较缩写
				{
					monmode = 0;//借用monmode
					for (int j = 0; j < i; ++j)//所有之前月份天数之和
					{
						monmode += months[j].days;
					}
					printf("今年已经过去了%d天。\n", monmode + date);
					return 0;//退出程序
				}
				break;
			default:
				if (strcmp(months[i].fullname, mon) == 0)//比较全名
				{
					monmode = 0;//借用monmode
					for (int j = 0; j < i; ++j)//所有之前月份天数之和
					{
						monmode += months[j].days;
					}
					printf("今年已经过去了%d天。\n", monmode + date);
					return 0;//退出程序
				}
				break;
			
		}
	}
	/*无匹配月份*/
	printf("无效的月份信息。\n");
	return 1;
}
void prime(struct month months [])
{
	char * abbrs[12] = {	//各个月的缩写
		"Jan.",
		"Feb.",
		"Mar.",
		"Apr.",
		"May.",
		"Jun.",
		"Jul.",
		"Aug.",
		"Sep.",
		"Oct.",
		"Nov.",
		"Dec."
		};	
	char * fullnames[12] = {	//各个月的全名
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"Septmber",
		"October",
		"November",
		"December"
		};	
	for (int i = 0; i < 12; ++i)
	{
		/*初始化一月到十二月*/
		strcpy(months[i].abbr, abbrs[i]);//复制缩写
		strcpy(months[i].fullname, fullnames[i]);//复制月份全名
		months[i].number = i + 1;//复制月份数字（1到12）
		/*初始化每月天数*/
		if (i == 1)
		{
			months[i].days = 28;//二月，暂不处理闰年
		}
		else
		{
			int flag = (i < 8)? 0: 1;
			if ((i + flag) % 2)
			{
				months[i].days = 30;//8月前的偶数月，8月后的奇数月
			}
			else
			{
				months[i].days = 31;//8月前的奇数月，8月后的偶数月
			}
		}
	}
}
