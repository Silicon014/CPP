/* min to hour */
#include<stdio.h>
char ifS(int);

int main(void)
{
	const int HOUR = 60,
		  TRUE = 1,
		  FALSE = 0;
	int min, hour;
	int s_hour, s_min;
	while (1)
	{
		printf("How many minutes(0 to quit): ");
		while (!scanf("%d", &min))
		{
			printf("Error. Please enter an integer.\n");
			while (getchar() != '\n')
				;
			printf("How many minutes(0 to quit): ");
			continue;
		}
		if (min < 1)
			break;
		hour = min / HOUR;
		min %= HOUR;
		if (hour > 1)
			s_hour = TRUE;
		else
			s_hour = FALSE;
		if (min > 1)
			s_min = TRUE; 
		else
			s_min = FALSE;
		printf("That's %d hour%c", hour, ifS(s_hour));
		if (min != 0)
			printf(" and %d minute%c .\n", min, ifS(s_min));
		else
			printf(".\n");
		while (getchar() != '\n')
			;
	}
	return 0;
}
char ifS(int boolean)
{
	if (boolean)
		return 's';
	else
		return ' ';
}

