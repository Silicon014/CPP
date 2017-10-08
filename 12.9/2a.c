#include<stdio.h>
static int mode;
static double distance;
static double fuel;
void set_mode(int n)
{
	if (mode > 1)
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		mode = 1;
	}
	else
		mode = n;
}
void get_info(void)
{
	printf("Enter distance traveled in %s: ",
		(!mode)? "kilometers": "miles");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in %s: ",
		(!mode)? "liters": "gallons");
	scanf("%lf", &fuel);
}
void show_info(void)
{
	if (mode)
	{
		printf("Fuel consumption is %.1lf miles per gallon.\n",
			distance / fuel);
	}
	else
	{
		printf("Fuel consumption is %.1lf liters per 100 km.\n",
			fuel / distance * 100);
	}
}
