#include<stdio.h>
int getnum(void);

int main(void)
{
	int num = getnum();

	for (int i = 0; i <= 10; ++i)
		printf("%d\n", num + i);
	return 0;
}
int getnum(void)
{
	int a;

	printf("Enter a num:\n");
	while (!scanf("%d", &a))
	{
		printf("Error. \n");
		printf("Enter a num again:\n");
		while (getchar() != '\n')
			continue;
	}
	while (getchar() != '\n')
		continue;
	return a;
}
	
