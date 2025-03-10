/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:06 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/10 19:08:40 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stak **stack_out, t_stak **stack_in)
{
	t_stak	*tmp;

	if (stack_out == 0 || *stack_out == 0)
		return ;
	tmp = *stack_out;
	*stack_out = (*stack_out)->next;
	if (stack_in == 0)
		*stack_in = tmp;
	else
	{
		tmp->next = *stack_in;
		*stack_in = tmp;
	}
}

void	push_a(t_elements	*vars)
{
	push(&vars->b, &vars->a);
	vars->moves ++;
	ft_printf("pb\n");
}

void	push_b(t_elements	*vars)
{
	push(&vars->a, &vars->b);
	vars->moves ++;
	ft_printf("pa\n");
}
