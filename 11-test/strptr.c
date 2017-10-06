/*strpr.c*/	//cpp p322 --program list 11.2
#include<stdio.h>
int main(void)
{
	printf("%s, %p, %c\n","we", "are", *"space farers");
	return 0;
}
/*
	"space farers" as a pointer eq the pointer of 's'.
	thus *"~" eq 's'.

	"are" as a pointer eq the pointer of 'a'.

	%s: get the pointer of 'w', ++, til the pointer point to '\0'.
*/
