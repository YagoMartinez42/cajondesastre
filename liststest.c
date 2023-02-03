#include "lists.h"
#include <stdio.h>

int ascending(int a, int b)
{
	return (a <= b);
}
int int_equals(void* a, void* b)
{
	if (*(int*)a == *(int*)b)
		return (0);
	return (1);
}

int main(void)
{
	t_list* test_list;
	t_list* node;
	int len;
	int i = 1;
	int* n1 = NULL;
	int n2 = 5;

	len = (random() % 126) + 2;
	n1 = malloc(sizeof(int));
	*n1 = (random() % 512) - 128;
	test_list = ft_lstnew(n1);
	while (i < len)
	{
		n1 = malloc(sizeof(int));
		*n1 = (random() % 512) - 128;
		node = ft_lstnew(n1);
		ft_lstadd_back(&test_list, node);
		i++;
	}
	node = test_list;
	while (node != NULL)
	{
		printf("%i ", *(int*)(node->content));
		node = node->next;
	}
	printf("\n");
	ft_lstremove_if(&test_list, (void *)&n2, int_equals);
	node = test_list;
	while (node != NULL)
	{
		printf("%i ", *(int*)(node->content));
		node = node->next;
	}
	printf("\n");
	test_list = ft_lstsort(test_list, ascending);
	node = test_list;
	while (node != NULL)
	{
		printf("%i ", *(int*)(node->content));
		node = node->next;
	}
	printf("\n");
	return 0;
}
