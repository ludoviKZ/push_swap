#include "push_swap.h"

void	swap(t_stak	**head)
{
	t_stak	*tmp;

	if (!*head || (*head)->next == NULL)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
}

void	swap_a(t_elements	*vars)
{
	swap(&vars->a);
	write(1, "sa\n", 3);
}

void	swap_b(t_elements	*vars)
{
	swap(&vars->b);
	write(1, "sb\n", 3);
}

void	swap_ab(t_elements	*vars)
{
	swap(s&vars->a);
	swap(&vars->b);
	write(1, "ss\n", 3);
}