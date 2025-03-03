/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:15 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/03 20:36:03 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_elements *vars)
{
	int	first;

	first = find_first(vars->a);
	if (vars->a->pos == first)
		rotate_a(vars);
	else if (vars->a->next->pos == first)
		r_rotate_a(vars);
	if (vars->a->pos > vars->a->next->pos)
		swap_a(vars);
}

void	sort_five(t_elements *vars)
{
	int	size;

	size = vars->tot;
	while (size)
	{
		size --;
		if (vars->a->pos == 0 || vars->a->pos == 1)
			push_b(vars);
		else
			rotate_a(vars);
	}
	sort_three(vars);
	push_a(vars);
	push_a(vars);
	if (vars->a->pos > vars->a->next->pos)
		swap_a(vars);
}

void	sort_bad(t_elements *vars)
{
	int	largest;
	int	max_bits;
	int	i;
	int	n;

	largest = find_first(vars->a);
	max_bits = find_sizebit(largest);
	i = 0;
	while (i < max_bits)
	{
		n = 0;
		while (n <= largest)
		{
			if (((vars->a)->pos >> i) & 1)
				rotate_a (vars);
			else
				push_b(vars);
			n++;
		}
		while (vars->b)
			push_a(vars);
		i++;
	}
}
void smart_rota(t_elements *vars,int pos_next)
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
void smart_rotb(t_elements *vars,int pos_next)
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

int findquick (t_elements *vars, t_calcs *v)
{
	int node;

	node = findnode(vars->b, (v->copya->pos - 1));
	if (node > (count_nodes(vars->b)/2))
		node = (count_nodes(vars->b) - node + 1);
	if (node + v->add < v->least)
	{
		v->ret = v->pos;
		v->least = (node + v->add);
	}
}
int calcleast(t_elements *vars)
{
	t_calcs v;

	v.ret = 0;
	v.pos = 0;
	v.add = 0;
	v.least = INT_MAX;
	v.copya = vars->a;
	while( v.copya->next != 0)
	{
		v.add = findquick (vars, &v);
		if (v.pos <= (count_nodes(v.copya)/2))
			v.add ++;
		else
			v.add --; 
		v.copya = v.copya->next;
		v.pos ++;
	}
	return(v.ret);
}

void	sort_turk(t_elements *vars)
{
	int		to_push;

	vars->largest = find_first(vars->a);
	push_b(vars);
	push_b(vars);
	while (count_nodes(vars->a) > 2)
	{
		to_push = calcleast(vars);
		smart_rota(vars, calcleast(vars));
		smart_rotb(vars,findnode(vars->b, (vars->a->pos - 1)));
	}
	sort_three(vars);
	while (vars->b)
	{
		if (vars->a->pos != (vars->b->pos + 1) && vars->b->pos != vars->largest)
		{
			smart_rota(vars, findnode(vars->a, (vars->b->pos + 1)));
		}
		push_a(vars);
	}
}

void	sorting( t_elements *vars)
{
	vars->tot = count_nodes(vars->a);
	if (issorted(vars) == 1)
		return ;
	if (vars->tot <= 3)
		sort_three(vars);
	else if (vars->tot <= 5)
		sort_five(vars);
	else
		sort_turk(vars);
}
