#include "push_swap.h"

void	rotate_cw(t_stak **head)
{
	t_stak	*tail;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tail = *head;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *head;
	*head = (*head)->next;
	tail->next->next = NULL;
}

void	rotate_a(t_elements	*vars)
{
	rotate_cw(&vars->a);
	write (1, "ra\n", 3);
}

void	rotate_b(t_elements	*vars)
{
	rotate_cw(&vars->b);
	write (1, "rb\n", 3);
}

void	rotate_ab(t_elements	*vars)
{
	rotate_cw(&vars->a);
	rotate_cw(&vars->b);
	write(1, "rr\n", 3);
}