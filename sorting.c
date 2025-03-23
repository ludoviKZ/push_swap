/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:15 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/23 16:02:15 by lzorzit          ###   ########.fr       */
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

int	calcleast(t_stak *from, t_stak *to)
{
	t_calcs	v;

	v.ret = 0;
	v.pos = 0;
	v.add = 0;
	v.least = INT_MAX;
	v.copya = from;
	while (v.copya->next != 0)
	{
		v.ret = findquick (to, &v);
		if (v.pos <= (count_nodes(from) / 2))
			v.add ++;
		else
			v.add --;
		v.copya = v.copya->next;
		v.pos ++;
	}
	return (v.ret);
}

int	calcleastrev(t_stak *from, t_stak *to)
{
	t_calcs	v;

	v.half = count_nodes(from) / 2;
	v.ret = 0;
	v.pos = 0;
	v.add = 0;
	v.least = INT_MAX;
	v.copya = from;
	while (v.copya->next != 0)
	{
		v.ret = findquickrev (to, &v);
		if (v.pos <= v.half)
			v.add ++;
		else
			v.add --;
		v.copya = v.copya->next;
		v.pos ++;
	}
	return (v.ret);
}

void	sort_turk(t_elements *vars)
{
	int	rota;
	int	rotb;
	int	to_pushval;

	push_b(vars);
	push_b(vars);
	while (count_nodes(vars->a) > 3)
	{
		to_pushval = node_pos(vars->a, calcleast(vars->a, vars->b));
		rota = smart_rota(vars, calcleast(vars->a, vars->b));
		rotb = smart_rotb(vars, nextleast(vars->b, (to_pushval -1)));
		bunchmoves(vars, &rota, &rotb, 'b');
	}
	sort_three(vars);
	while (vars->b)
	{
		to_pushval = node_pos(vars->b, calcleastrev(vars->b, vars->a));
		rotb = smart_rotb(vars, calcleastrev(vars->b, vars->a));
		rota = smart_rota(vars, findnode(vars->a, (to_pushval + 1)));
		bunchmoves(vars, &rota, &rotb, 'a');
	}
	rota = smart_rota(vars, findnode(vars->a, (0)));
	bunchmoves(vars, &rota, &rotb, 'a');
}
