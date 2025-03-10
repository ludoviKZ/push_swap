/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackuseutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:09:07 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/10 15:09:09 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_first(t_stak *head)
{
	t_stak	*copy;
	int		largest;

	largest = INT_MIN;
	copy = head;
	while (copy)
	{
		if (copy->pos > largest)
			largest = copy->pos;
		copy = copy->next;
	}
	return (largest);
}

int node_pos (t_stak *stack, int i)
{
	t_stak	*copy;
	int		ret;
	int		move;

	move = 0;
	copy = stack;
	ret = -1;
	while (copy && move < i)
	{
		copy = copy->next;
		move ++;
	}
	ret = copy->pos;
	return (ret);
}

void	print_list(t_stak *head)
{
	t_stak	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		ft_printf("node: %d: %d	pos: %d\n", i, current->val, current-> pos);
		i++;
		current = current->next;
	}
}