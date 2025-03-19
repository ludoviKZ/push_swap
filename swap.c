/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:27 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/19 17:17:50 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stak	**stack)
{
	t_stak	*tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	swap_a(t_elements	*vars)
{
	swap(&vars->a);
	vars->moves ++;
	ft_printf("sa\n");
}

void	swap_b(t_elements	*vars)
{
	swap(&vars->b);
	vars->moves ++;
	ft_printf("sb\n");
}

void	swap_ab(t_elements	*vars)
{
	swap(&vars->a);
	swap(&vars->b);
	vars->moves ++;
	ft_printf("ss\n");
}
