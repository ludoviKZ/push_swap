/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:16:57 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/19 17:17:25 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stak **stack)
{
	t_stak	*tail;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tail = *stack;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = *stack;
	*stack = (*stack)->next;
	tail->next->next = NULL;
}

void	rotate_a(t_elements	*vars)
{
	rotate(&vars->a);
	vars->moves ++;
	ft_printf("ra\n");
}

void	rotate_b(t_elements	*vars)
{
	rotate(&vars->b);
	vars->moves ++;
	ft_printf("rb\n");
}

void	rotate_ab(t_elements	*vars)
{
	rotate(&vars->a);
	rotate(&vars->b);
	vars->moves ++;
	ft_printf("rr\n");
}
