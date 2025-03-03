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
	int		closest;
	t_stak	*copy;

	
	copy = stack;
	posit = 0;
	closest = INT_MAX;
	if (copy->pos < closest && copy->pos > find)
			closest = copy->pos;
	while (copy->pos != find && copy->next != 0)
	{
		copy = copy->next;
		posit ++;
		if (copy->pos < closest && copy->pos > find)
			closest = copy->pos;
	}
	ft_printf("test%i\n", find);
	if (copy->pos == find)
		return(posit);
	else if (closest < 999)
		return(findnode(stack, closest));
	else
	{
		ft_printf("test%i\n", find);
		exit(0);
	}
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

void	smart_rota(t_elements *vars,int pos_next)
{
	int		stack_size;

	stack_size = count_nodes(vars->a);
	if (pos_next <= stack_size/2)
	{
		while (pos_next-- != 0)
			rotate_a(vars);
	}
	else
	{
		while ((stack_size - pos_next) != -1)
		{
			r_rotate_a(vars);
			pos_next ++;
		}
	}
}

void	smart_rotb(t_elements *vars,int pos_next)
{
	int		stack_size;

	stack_size = count_nodes(vars->b);
	if (pos_next <= stack_size/2)
	{
		while (pos_next-- != 0)
			rotate_b(vars);
	}
	else
	{
		while ((stack_size - pos_next) != -1)
		{
			r_rotate_b(vars);
			pos_next ++;
		}
	}
}

int	findquick (t_elements *vars, t_calcs *v)
{
	int node;
	if (v->copya->pos > find_first(vars->b))
		node = findnode(vars->b, 0);
	else
		node = findnode(vars->b, (v->copya->pos + 1));
	if (node > (count_nodes(vars->b)/2))
		node = (count_nodes(vars->b) - node + 1);
	if (node + v->add < v->least)
	{
		v->ret = v->pos;
		v->least = (node + v->add);
	}
	return (v->ret);
}
