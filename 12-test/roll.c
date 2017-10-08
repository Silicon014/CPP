#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	printf("Press Enter to Roll,"
	" else to quit.\n");
	while (getchar() != EOF)
	printf("%d", rand() % 6 + 1);
	putchar('\n');
	puts("quit.");
	return 0;
}
