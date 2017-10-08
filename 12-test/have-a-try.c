#include<stdio.h>
#include<stdlib.h>
#define BS 1024*1024	//BS为1024
int main(void)
{
	while (1)
		malloc(BS);	//使用大小为BS的内存区域
	return 0;
}
