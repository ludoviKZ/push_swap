/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:20 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/10 19:28:31 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	findnode(t_stak *stack, int find)
{
	int		posit;
	int		closest;
	t_stak	*copy;

	copy = stack;
	posit = 0;
	closest = INT_MAX;
	if (find > find_first(stack))
		return (findnode(stack, (0)));
	if (copy->pos < closest && copy->pos > find)
		closest = copy->pos;
	while (copy->pos != find && copy->next != 0)
	{
		copy = copy->next;
		posit ++;
		if (copy->pos < closest && copy->pos > find)
			closest = copy->pos;
	}
	if (copy->pos == find)
		return (posit);
	else
		return (findnode(stack, closest));
}

int	findquickrev(t_stak *to, t_calcs *v)
{
	int	node;

	if (v->copya->pos > find_first(to))
		node = findnode(to, 0);
	else
		node = findnode(to, (v->copya->pos + 1));
	if (node > (count_nodes(to) / 2))
		node = (count_nodes(to) - node);
	if (node + v->add < v->least)
	{
		v->ret = v->pos;
		v->least = (node + v->add);
	}
	return (v->ret);
}

int	findquick(t_stak *to, t_calcs *v)
{
	int	node;

	node = nextleast(to, (v->copya->pos - 1));
	if (node > (count_nodes(to) / 2))
		node = (count_nodes(to) - node);
	if (node + v->add < v->least)
	{
		v->ret = v->pos;
		v->least = (node + v->add);
	}
	return (v->ret);
}
int nextleast(t_stak *to, int i)
{
	int		n;
	int		next;

	next = i;
	n = node_pos(to, findnode(to, i));
	if ( n == i)
		return (findnode(to, i));
	while (next > 0)
	{
		next --;
		n = node_pos(to, findnode(to, next));
		if (n <= next && n != 0)
			return (findnode(to, next));
	}
	return (findnode(to, find_first(to)));
}
