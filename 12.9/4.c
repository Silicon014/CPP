#include<stdio.h>
int time = 0;
int times();
int main(void)
{
	while (time + 1)
	{
		printf("loop: %d\n", times());
		printf("Enter to continue, or EOF to quit: ");
		switch (getchar())
		{
			case EOF:
				time = -1;
				break;
			case '\n':
				break;
			default:
				break;
		}
	}
	puts("Done.");
	return 0;
}
int times(void)
{
	++time;
	return time;
}
