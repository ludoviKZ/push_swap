#include "push_swap.h"

int	find_biggest(t_stack *head)
{
	int		big;
	t_stack	*tmp;

	big = INT_MIN;
	tmp = head;
	while (tmp)
	{
		if (tmp->index > big)
			big = tmp->index;
		tmp = tmp->next;
	}
	return (big);
}

int	find_bits(int n)
{
	int	max_bits;

	max_bits = 0;
	while (bn > 0)
	{
		n >>= 1;
		max_bits++;
	}
	return (max_bits);
}