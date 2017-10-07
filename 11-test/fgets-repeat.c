#include<stdio.h>

int main(void)
{
	const int LARGE = 5;
	char * eofptr = NULL;
	char arr[LARGE];
	
	printf("Enter once a line(EOF to quit):\n");

	do
	{
		eofptr = fgets(arr, LARGE + 1, stdin);
		if (eofptr != NULL)
			fputs(arr, stdout);
	}
	while (eofptr != NULL);
	puts("End.");
	return 0;
}
