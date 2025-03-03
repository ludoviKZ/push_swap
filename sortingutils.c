/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:20 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/03 20:33:06 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findnode(t_stak *stack, int find)
{
	int		posit;
	int		closestval;
	int		closest;
	t_stak	*copy;

	copy = stack;
	posit = 0;
	closest = 0;
	if (copy->pos > closest && copy->pos < find)
			closest == copy->pos;
	while (copy->pos != find || copy->next != 0)
	{
		copy = copy->next;
		posit ++;
		if (copy->pos > closest && copy->pos < find)
			closest = copy->pos;
	}
	if (copy->pos == find)
		return(posit);
	else
		return(findnode(stack, closest));
}

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