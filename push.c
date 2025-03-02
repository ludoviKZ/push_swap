#include "push_swap.h"

void	push(t_stak **stack_from, t_stak **stack_to)
{
	t_stak	*tmp;

	if (stack_from == NULL || *stack_from == NULL)
		return ;
	tmp = *stack_from;
	*stack_from = (*stack_from)->next;
	if (stack_to == NULL)
		*stack_to = tmp;
	else
	{
		tmp->next = *stack_to;
		*stack_to = tmp;
	}
}

void	push_a(t_elements	*vars)
{
	push(&vars->b, &vars->a);
	write(1, "pa\n", 3);
}

void	push_b(t_elements	*vars)
{
	push(&vars->a, &vars->b);
	write(1, "pb\n", 3);
}