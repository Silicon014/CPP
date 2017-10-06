#include<stdio.h>
/*读取输入流的字符数，以EOF结尾*/

int main(void)
{
	int i;//统计读取的字符数

	while (getchar() != EOF)
		++i;
	printf("%d chars in total.\n", i);
	return 0;
}
