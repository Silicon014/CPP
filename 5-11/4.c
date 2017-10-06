#include<stdio.h>
float heightis(void);

int main(void)
{
	const float INCH = 2.54;	
	const int FEET = 12;
	float inch, cm;
	int feet;

	while ((cm = heightis()) > 0)
	{
		inch = cm / INCH;
		feet = (int)inch / FEET;
		inch -= feet * (float)FEET;
		printf("%.1f cm = %d feet, %.1f inches\n",
			cm, feet, inch);
	}
	return 0;
}
float heightis(void)
{
	float returner;

	printf("Enter a height in centimeters (<=0 to quit): ");
	while (!scanf("%f", &returner))
	{
		printf("Enter a height in centimeters (<=0 to quit): ");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	return returner;
}	
