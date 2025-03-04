/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:17:03 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/04 18:43:29 by lzorzit          ###   ########.fr       */
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

void	free_matrixps(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	while (i > 0)
	{
		i --;
		if (mat[i])
			free(mat[i]);
	}
	free(mat);
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

int	main(int argc, char **argv)
{
	t_elements	vars;

	vars.moves = 0;
	if (isvalid(argc, argv) == 0)
		return (ft_printf("imput invalid"), 0);
	vars.a = init_list(argc, argv);
	vars.b = 0;
	setpos(vars.a, count_nodes(vars.a));
	print_list(vars.a);
	sorting(&vars);
	if (issorted(&vars) == 0)
		ft_printf("error, failed to sort\n");
	free_stacks(&vars);
	return (0);
}
