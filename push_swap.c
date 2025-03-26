/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:03 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/26 17:09:59 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	issorted(t_elements *vars)
{
	t_stak	*copy;

	copy = vars->a;
	while (copy && copy->next)
	{
		if (copy->pos > copy->next->pos)
			return (0);
		copy = copy->next;
	}
	return (1);
}

void	free_matrixps(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	while (i > 0)
	{
		i --;
		if (arr[i])
			free(arr[i]);
	}
	free(arr);
}

void	free_stacks(t_elements	*vars)
{
	t_stak	*copy;

	while (vars->a != 0)
	{
		copy = vars->a;
		vars->a = vars->a->next;
		free(copy);
	}
	while (vars->b != 0)
	{
		copy = vars->b;
		vars->b = vars->b->next;
		free(copy);
	}
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

int	main(int argc, char **argv)
{
	t_elements	vars;

	vars.moves = 0;
	if (argc < 2 || argv[1][0] == '\0')
		return (0);
	if (isvalid(argc, argv) == 0)
		return (ft_printf("Error\n"), 0);
	vars.a = init_list(argc, argv);
	vars.b = 0;
	setpos(vars.a, count_nodes(vars.a));
	sorting(&vars);
	free_stacks(&vars);
	return (0);
}
