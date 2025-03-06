/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:12 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/06 17:16:00 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate(t_stak **stack)
{
	t_stak	*prev_tail;
	t_stak	*new_tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	prev_tail = *stack;
	while (prev_tail->next != NULL)
	{
		new_tail = prev_tail;
		prev_tail = prev_tail->next;
	}
	prev_tail->next = *stack;
	new_tail->next = NULL;
	*stack = prev_tail;
}

void	r_rotate_a(t_elements	*vars)
{
	r_rotate(&vars->a);
	vars->moves ++;
	ft_printf("rra\n");
}

void	r_rotate_b(t_elements	*vars)
{
	r_rotate(&vars->b);
	vars->moves ++;
	ft_printf("rrb\n");
}

void	r_rotate_ab(t_elements	*vars)
{
	r_rotate(&vars->a);
	r_rotate(&vars->b);
	vars->moves --;
	ft_printf("rrr\n");
}
