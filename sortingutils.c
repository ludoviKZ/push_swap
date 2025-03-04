/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:20 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/04 18:43:00 by lzorzit          ###   ########.fr       */
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

void bunchswap(t_elements *vars, int *rota, int *rotb)
{
	while (rota[0] != 0 && rota[0] > 0)
	{
		rotate_a(vars);
		rota[0]--;
	}
	while (rota[0] != 0 && rota[0] < 0)
	{
		r_rotate_a(vars);
		rota[0]++;
	}
	while (rotb[0] != 0 && rotb[0] > 0)
	{
		rotate_b(vars);
		rotb[0]--;
	}
	while (rotb[0] != 0 && rotb[0] < 0)
	{
		r_rotate_b(vars);
		rotb[0]++;
	}
}

void bunchmoves(t_elements *vars, int *rota, int *rotb, int push)
{
	if (rota[0] > 0 && rotb[0] > 0)
	{
		while(rota[0] != 0 && rotb[0] != 0)
		{
			rotate_ab(vars);
			rota[0] --;
			rotb[0] --;
		}
	}
	if (rota[0] < 0 && rotb[0] < 0)
	{
		
		while(rota[0] != 0 && rotb[0] !=0)
		{
			r_rotate_ab(vars);
			rota[0] ++;
			rotb[0] ++;
		}
	}
	bunchswap(vars, rota, rotb);
	if (push == 'b')
		push_b(vars);
	else
		push_a(vars);
	rotb[0] = 0;
	rota[0] = 0;
}

int	smart_rota(t_elements *vars,int pos_next)
{
	int		ret;
	int		stack_size;

	ret = 0;
	stack_size = count_nodes(vars->a);
	if (pos_next <= stack_size/2)
	{
		while (pos_next != 0)
		{
			pos_next --;
			ret ++;
		}
	}
	else
	{
		while ((stack_size - pos_next) != 0)
		{
			ret --;
			pos_next ++;
		}
	}
	return (ret);
}

int	smart_rotb(t_elements *vars,int pos_next)
{
	int		ret;
	int		stack_size;

	ret = 0;
	stack_size = count_nodes(vars->b);
	if (pos_next <= stack_size/2)
	{
		while (pos_next != 0)
		{
			pos_next --;
			ret ++;
		}
	}
	else
	{
		while ((stack_size - pos_next) != 0)
		{
			ret --;
			pos_next ++;
		}
	}
	return(ret);
}

int	findquick (t_stak *to, t_calcs *v)
{
	int node;
	if (v->copya->pos > find_first(to))
		node = findnode(to, 0);
	else
		node = findnode(to, (v->copya->pos + 1));
	if (node > (count_nodes(to)/2))
		node = (count_nodes(to) - node + 1);
	if (node + v->add < v->least)
	{
		v->ret = v->pos;
		v->least = (node + v->add);
	}
	return (v->ret);
}
