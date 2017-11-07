#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct month {
	int number;
	int days;
	char fullname[15];
	char abbr[5];
	};
void prime(struct month months []);
int main(void)
{
	int year, date, monmode;
	char mon[15];
	struct month months[12];

	printf("输入年、月、日：\n");
	printf("年份：");
	scanf("%d", &year);
	printf("月份：");
	scanf("%15s", mon);
	printf("日期：");
	scanf("%d", &date);

	prime(months);
	if (!(year % 4))
	{
		months[1].days++;
	}
	monmode = strlen(mon);
	
	for (int i = 0; i < 12; ++i)
	{
		switch (monmode)
		{
			case 1:
			case 2:
				if (months[i].number == atoi(mon))
				{
					monmode = 0;
					for (int j = 0; j < i; ++j)
					{
						monmode += months[j].days;
					}
					printf("今年已经过去了%d天。\n", monmode + date);
					return 0;
				}
				break;
			case 4:
				if (strcmp(months[i].abbr, mon) == 0)
				{
					monmode = 0;
					for (int j = 0; j < i; ++j)
					{
						monmode += months[j].days;
					}
					printf("今年已经过去了%d天。\n", monmode + date);
					return 0;
				}
				break;
			default:
				if (strcmp(months[i].fullname, mon) == 0)
				{
					monmode = 0;
					for (int j = 0; j < i; ++j)
					{
						monmode += months[j].days;
					}
					printf("今年已经过去了%d天。\n", monmode + date);
					return 0;
				}
				break;
			
		}
	}
	printf("无效的月份信息。\n");
	return 1;
}
void prime(struct month months [])
{
	char * abbrs[12] = {
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
	char * fullnames[12] = {
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
		strcpy(months[i].abbr, abbrs[i]);
		strcpy(months[i].fullname, fullnames[i]);
		months[i].number = i + 1;
		if (i == 1)
		{
			months[i].days = 28;
		}
		else
		{
			if (i % 2)
			{
				months[i].days = 30;
			}
			else
			{
				months[i].days = 31;
			}
		}
	}
}
