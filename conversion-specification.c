/* conversion-specification.c */

#include<stdio.h>
int main(void)
{
	int i = 1;
	printf("int = %d, float = %f or %e or %E,\n",
		i, (float)i, (float)i, (float)i);
	i = 10;
	printf("%i: ", i);
	printf("unsigned(%%u): %u ", (unsigned)i);
	printf("or: \n");
	printf("%%o: %o\n", (unsigned)i);
	printf("%%x: %x %%X: %X\n",
		(unsigned)i, (unsigned)i);
	printf("\nThe address of i: %p\n", &i);
	printf("now %i\n:", i = 1000);
	printf("%%g / %%G: %g\n",(double)i);
	printf("now %i:\n", i = 1000000);
	printf("%%g: %g  %%G: %G\n", (double)i, (double)i);
	i = 1;
	printf("now %f:\n",(double)i * 0.000001);
	printf("%%g = %g, %%G = %G\n",
		(double)i * 0.000001, (double)i * 0.000001);
	char c = 'A';
	printf("char c = %c\n", c);
	printf("string: %s\n", "This is a string.");
	printf("what does %%a or %%A mean?\n");
	printf("Try double i by %%a: %a\n", (double)i);
	printf("Let's call it a day.\n");
	
	return 0;
}

	
