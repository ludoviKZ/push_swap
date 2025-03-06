/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:15 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/06 17:44:39 by lzorzit          ###   ########.fr       */
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

int calcleast(t_stak *from, t_stak *to)
{
	t_calcs v;

	v.ret = 0;
	v.pos = 0;
	v.add = 0;
	v.least = INT_MAX;
	v.copya = from;
	while( v.copya->next != 0)
	{
		v.ret = findquick (to, &v);
		if (v.pos <= (count_nodes(from)/2))
			v.add ++;
		else
			v.add --; 
		v.copya = v.copya->next;
		v.pos ++;
	}
	ft_printf("\n||%i--%i", v.ret, v.least);
	return(v.ret);
}
int calcleastrev(t_stak *from, t_stak *to)
{
	t_calcs v;

	v.ret = 0;
	v.pos = 0;
	v.add = 0;
	v.least = INT_MAX;
	v.copya = from;
	while( v.copya->next != 0)
	{
		v.ret = findquickrev (to, &v);
		if (v.pos <= (count_nodes(from)/2))
			v.add ++;
		else
			v.add --; 
		v.copya = v.copya->next;
		v.pos ++;
	}
	ft_printf("\n||%i--%i", v.ret, v.least);
	return(v.ret);
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


void	sort_turk(t_elements *vars)
{
	int	rota;
	int	rotb;
	int to_pushval;

	push_b(vars);
	push_b(vars);
	while (count_nodes(vars->a) > 3)
	{
		to_pushval = node_pos(vars->a, calcleast(vars->a, vars->b));
		rota = smart_rota(vars, calcleast(vars->a, vars->b));
		if (to_pushval > find_first(vars->b))
			rotb = smart_rotb(vars, findnode(vars->b, (0)));
		else
			rotb = smart_rotb(vars, findnode( vars->b, (to_pushval -1)));
		ft_printf("|| %i|| %i\n", rota, rotb);
		bunchmoves(vars, &rota, &rotb, 'b');
	}
	sort_three(vars);
	while (vars->b)
	{
		to_pushval = node_pos(vars->b, calcleastrev(vars->b, vars->a));
		rotb = smart_rotb(vars, calcleastrev(vars->b, vars->a));
		if (to_pushval > find_first(vars->a))
			rota = smart_rota(vars, findnode(vars->a, (0)));
		else
			rota = smart_rota(vars, findnode(vars->a, (to_pushval + 1)));
		bunchmoves(vars, &rota, &rotb, 'a');
	}
	rota = smart_rota(vars, findnode(vars->a, (0)));
	bunchmoves(vars, &rota, &rotb, 'a');
	printf("\nmovesmade %i\n", vars->moves);
}

void	sorting( t_elements *vars)
{
	vars->largest = find_first(vars->a);
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
