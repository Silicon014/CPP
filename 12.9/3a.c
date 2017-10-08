#include<stdio.h>
int set_mode(int n)
{
	if (n > 1)
	{
		printf("Invalid mode specified. Mode 1(US) used.\n");
		return 1;
	}
	else
		return n;
}
double get_info(int mode)
{
	double fuel;
	double distance;

	printf("Enter distance traveled in %s: ",
		(!mode)? "kilometers": "miles");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in %s: ",
		(!mode)? "liters": "gallons");
	scanf("%lf", &fuel);
	return distance / fuel;
}
void show_info(int mode, double i)
{
	if (mode)
	{
		printf("Fuel consumption is %.1lf miles per gallon.\n",
			i);
	}
	else
	{
		printf("Fuel consumption is %.1lf liters per 100 km.\n",
			1.0 / i * 100);
	}
}
