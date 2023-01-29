#include "lists.h"

int main(void)
{
	t_list* test_list;
	t_list* node;
	int content[20] = {5,5,2,6,78,23,5,72,59,10,1,-2,-2,-9,12,-25,-90,99,-7,33};
	int i = 1;

	test_list = ft_listnew(content);

	while (i < 20)
	{
		node = ft_lstnew(content + i)
		ft_lstadd_back(&test_list, node);
	}
	return 0;
}
