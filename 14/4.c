#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct doc {	//结构模板
	char ID[10];
	struct {	//匿名结构
		char firstname[20];
		char middlename;
		char lastname[20];
		};
	};
void docprint(struct doc [], int);
int main(void)
{
	struct doc names[10];
	int i = 0;
	char midname[20];

	do
	{
		printf("输入名：");
		scanf("%s", names[i].firstname);
		while (getchar() != '\n')
			continue;
		printf("输入姓：");
		scanf("%s", names[i].lastname);	
		while (getchar() != '\n')
			continue;
		printf("输入中间名(EOF以跳过): ");
		if (scanf("%s", midname) != EOF)
		{
			names[i].middlename = midname[0];
			while (getchar() != '\n')
				continue;
		}
		else
		{
			names[i].middlename = '\0';
			putchar('\n');
		}
		printf("输入ID：");
		scanf("%9s", names[i].ID);
		while (getchar() != '\n')
			continue;
		printf("是否添加下一项？EOF以取消。\n");
		if (getchar() == EOF)
		{
			++i;
			break;
		}
		++i;
	}
	while (i < 9);
	docprint(names, i);
	return 0;
}
void docprint(struct doc names[], int lim)
{
	for (int i = 0; i < lim; ++i)
	{
		printf("%s, ", (names + i)->lastname);
		printf("%s ", (names + i)->firstname);
		if ((names + i)->middlename)
		{
			printf("%c, ", (names + i)->middlename);
		}
		printf("-- %s\n", (names + i)->ID);
	}
}
