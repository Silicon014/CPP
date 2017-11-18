#include<stdio.h>
#include<stdlib.h>
struct num {
	int n;
	struct num * next;
	};
int main(void)
{
	struct num * a = (struct num *) malloc(sizeof(struct num));
	struct num * i = a;

	/*获取并用链表存储一连串数字*/
	printf("输入数字，或输入EOF（Ctrl+D）退出：");
	while (scanf("%d", &i->n) != EOF)
	{
		while (getchar() != '\n')
			continue;
		i = i->next = (struct num *) malloc(sizeof(struct num));
		printf("输入下一个数字，或输入EOF退出：");
	}
	putchar('\n');
	i->next = NULL;
	i = a;
	/*打印链表中的数字*/
	while (i->next != NULL)
	{
		printf("%d\n", i->n);
		i = i->next;
	}
	i = a;
	/*释放链表*/
	while ((a = i->next) != NULL)
	{
		free(i);
		i = a;
	}
	free(a);

	return 0;
}
