#include "push_swap.h"

int	sorted(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	while (tmp && tmp->next)
	{
		if (tmp->pos > tmp->next->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	find_biggest(t_stak *head)
{
	int		big;
	t_stak	*tmp;

	big = INT_MIN;
	tmp = head;
	while (tmp)
	{
		if (tmp->pos > big)
			big = tmp->pos;
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