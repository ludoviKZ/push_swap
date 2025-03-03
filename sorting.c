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

int calcleast(t_elements *vars)
{
	t_calcs v;

	v.ret = 0;
	v.pos = 0;
	v.add = 0;
	v.least = INT_MAX;
	v.copya = vars->a;
	while( v.copya->next != 0 && v.pos < 20)
	{
		v.ret = findquick (vars, &v);
		if (v.pos <= (count_nodes(v.copya)/2))
			v.add ++;
		else
			v.add --; 
		v.copya = v.copya->next;
		v.pos ++;

	}
	printf("%i", v.ret);
	exit (0);
	return(v.ret);
}

void	sort_turk(t_elements *vars)
{
	int rep = 0;
	vars->largest = find_first(vars->a);
	push_b(vars);
	push_b(vars);
	while (count_nodes(vars->a) > 2)
	{
		if (rep++ >= 30)
		{print_list(vars->a); print_list(vars->b);
			exit(0);
		}
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
