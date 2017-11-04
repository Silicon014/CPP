#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

static char name[64];

FILE * openfile(char filename[], char mod[]);
/*
 *	filename是文件名，mod是打开的模式
 *	返回文件指针
 *	打开错误时报错，并返回空指针
 */
int addfile(FILE * target, FILE * source);
//
//	把source的内容添加到target的末尾
//	正常返回0，出错时返回1，结尾返回EOF
//
int catfile(FILE * fp);
//
//	逐次打印fp的所有内容
//	正常时返回0
//	错误时返回1
//

char * readname(void);
/*
 *	从输入中获取一个文件名
 *	并输出文件名以确认
 *	文件名最大长度为63
 */

int main(void)
{
	FILE * fp;
	FILE * in;

	fprintf(stdout, "Enter the name of target file: ");
	fflush(stdout);
	while ((fp = openfile(readname(), "a+")) == NULL)
	{
		fprintf(stderr, "Error: cannot open file \"%s\"\n", name);
		fprintf(stdout, "Enter another filename: ");
		fflush(stdout);
	}
	for (int i = 1; fprintf(stdout, "Enter the name of source file #%d: ", i); ++i)
	{
		if ((in = openfile(readname(), "r")) == NULL)
		{
			fprintf(stderr, "Error: cannot open file \"%s\"\n", name);
		}
		else
		{
			if (addfile(fp, in))
			{
			}
		}
	}
	
