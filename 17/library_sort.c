#include<stdio.h>
#include<stdlib.h>
#include<time.h>//提供time()函数

/*双链表的结构原型*/
struct list {
	struct list * prev;
	int n;
	struct list * next;
	};
struct list * makelist(int n)//创建n项的双链表
{
	struct list * head = (struct list *) malloc(sizeof(struct list));
	struct list * current;
	
	srand((unsigned int) time(NULL));//设置随机数种子
	current = head;
	current->prev = NULL;//链表开始
	for (int i = 0; i < n; ++i)
	{
		current->n = (int) rand() % 10;//随机生成0到9之间的数
		current->next = (struct list *) malloc(sizeof(struct list));//分配链表的下一项,并赋给next指针
		current->next->prev = current;//为下一项的perv指针赋值
		current = current->next;//转至下一项
	}
	current->next = NULL;//链表结束,最后一项为空
	return head;//返回链表的第一项
}
struct list * library_sort(struct list * head)
{
	struct list * i;
	struct list * j;
	struct list * tmp;

	i = head->prev = (struct list *) malloc(sizeof(struct list));//添加空白的第一项以便简化情况
	i->next = head;
	i->prev = NULL;
	head = i;//转至第一项
	while (i->next != NULL)//从第一项开始
	{
		if ((j = i->prev) != NULL)
		{
			tmp = i;
			i = i->next;//i转至下一项，本项由tmp处理
			//跳至tmp应插入的位置
			while (j->n > tmp->n && j->prev != NULL)
			{
				j = j->prev;
			}
			/*tmp从链表中脱离*/
			(tmp->next)->prev = tmp->prev;
			(tmp->prev)->next = tmp->next;
			/*tmp插入新位置*/
			(j->next)->prev = tmp;
			tmp->next = j->next;
			tmp->prev = j;
			j->next = tmp;
		}
		else
			i = i->next;//跳过首项
	}
	head = head->next;
	free(head->prev);
	head->prev = NULL;//删除添加的空白项
	return head;//返回链表的第一项
}
void print_list(struct list * head)//打印链表中的值n
{
	while (head->next != NULL)
	{
		printf("%d\t", head->n);//打印n
		head = head->next;//转至下一项
	}
	putchar('\n');//输出完毕换行
}
int freelist(struct list * head)
{
	/*释放链表*/
	struct list * i, * j;
	i = head;
	do
	{
		j = i->next;
		free(i);
		i = j;
	}
	while (j != NULL);
	return (int) j;
}
int main(int argc, char * argv [])
{
	struct list * ptr;//创建一个空链表
	int n;

	if (argc < 2)
	{
		/*提示输入命令行参数*/
		fprintf(stderr, "Usage: %s n (n = 1, 2, 3, ...)\n", *argv);
		exit(1);
	}
	if ((n = atoi(argv[1])) == 0)//用命令行参数给n赋值
	{
		/*提示命令行参数无效*/
		fprintf(stderr, "Invalid value of num n.\n");
		exit(1);
	}
	ptr = makelist(n);//生成一个n项的双链表

	/*打印随机生成的n项链表*/
	printf("Origin:\n");
	print_list(ptr);

	//对链表进行排序
	ptr = library_sort(ptr);

	/*打印排序后的链表*/
	printf("Sorted:\n");
	print_list(ptr);

	//释放链表
	freelist(ptr);

	return 0;
}
