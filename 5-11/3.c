#include<stdio.h>
int daysnum(void);

int main(void)
{
	const int WEEK = 7;
	int weeks, days, remaindays;

	while((days = daysnum()) > 0)
	{
		weeks = days / WEEK;
		remaindays = days % WEEK;
		printf("%d %s ", days,
			(days > 1)? "days": "day");
		printf("are ");
		printf("%i %s, ", weeks,
			(weeks > 1)? "weeks": "week");
		printf("%d %s.\n", remaindays,
			(remaindays > 1)? "days": "day");
	}
	return 0;
}
int daysnum(void)
{
	int num;
	
	printf("How many days(0 to quit):\n");
	while (!scanf("%i", &num))
	{
		printf("Wrong. Enter again(0 to quit):\n");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	return num;
}
