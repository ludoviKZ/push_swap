#include "push_swap.h"

void	rotate_ccw(t_stak **head)
{
	t_stak	*prev_tail;
	t_stak	*new_tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	prev_tail = *head;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *head;
	new_tail->next = NULL;
	*head = prev_tail;
}

void	r_rotate_a(t_elements	*vars)
{
	rotate_ccw(&vars->a);
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_elements	*vars)
{
	rotate_ccw(&vars->b);
	write(1, "rrb\n", 4);
}

void	r_rotate_ab(t_elements	*vars)
{
	rotate_ccw(&vars->a);
	rotate_ccw(&vars->b);
	write(1, "rrr\n", 4);
}