#include<stdio.h>
void critic(int * unit);
int main(void)
{
	int units;
	int * unit = &units;
	printf("How many pounds to a firkin of butter?\n");
	scanf("%d", unit);
	while (units != 56)
		critic(unit);
	printf("You must have looked it up!\n");
	return 0;
}
void critic(int * unit)
{
	printf("No luck, my friend. Try it again.\n");
	scanf("%d", unit);
}
