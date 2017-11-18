#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct list {
	int n;
	struct list * next;
	};
struct list * mklist(int n)
{
	/*创建项数为n的链表*/
	struct list * head, * current, * prev;

	if (!(n > 0))
	{
		fprintf(stderr, "Invalid n value.\n");
		exit(1);
	}
	prev = NULL;
	srand((unsigned int) time(NULL));
	for (int i = 0; i < n; ++i)
	{
		current = (struct list *) malloc(sizeof(struct list));
		current->n = (int) rand % 10;
		if (prev)
		{
			prev->next = current;
		}
		else
		{
			head = current;//首项
		}
		prev = current;
	}
	current->next = NULL;
	return head;
}
struct list * bubble_sort(struct list * head)
{
	struct list * i = head;

	while (i->next)
	{
		if (i->n > i->next->n)
		{
			i->n ^= i->next->n ^= i->n ^= i->next->n;//交换i->n和i->next->n的值
		}
		i = i->next;
	}
	return head;
}
int printlist(struct list * head)
{
	int i = 0;
	
	while (head->next)
	{
		printf("%d\t", head->n);
		head = head->next;
		++i;
	}
	printf("%d\n", head->n);
	++i;
	return i;
}
int freelist(struct list * head)
{
	struct list * i;
	
	while (head->next)
	{
		i = head;
		head = head->next;
		free(i);
	}
	free(head);

	return (int) i;
}
int main(int argc, char * argv [])
{
	struct list * i;

	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s n (n = 1, 2, 3, ...)\n", *argv);
		exit(1);
	}
	i = mklist(atoi(argv[1]));
	printf("Origin:\n");
	printf("%d in total.\n", printlist(i));
	putchar('\n');
	i = bubble_sort(i);
	printf("Sorted:\n");
	printf("%d in total.\n", printlist(i));
	freelist(i);
	return 0;
}
