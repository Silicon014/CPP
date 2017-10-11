#include<stdio.h>
#define CODES "#include<stdio.h>\nint main(void){puts(\"hello, world\");}"
/*提供CODES的含义*/
int main(void)
{
	FILE * fp = fopen("helloworld.c", "wx");	//打开一个空白文件
	fprintf(fp, CODES);	//向文件中写入CODES
	fclose(fp);	//退出文件
	return 0;
}
	/*之后，同目录下应该会出现helloworld.c这个文件。*/
