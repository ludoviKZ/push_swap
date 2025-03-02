#include "push_swap.h"

void	sort_three(t_elements *vars)
{
	int	first;

	first = find_biggest(vars->a);
	if (vars->a->pos == biggest)
		rotate_a(vars);
	else if (vars->a->next->pos == biggest)
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

// void	sort_turk(t_elements *vars)
// {
// 	int	largest;
// 	int	max_bits;
// 	int	i;
// 	int	n;

// 	largest = find_biggest(&vars->a);
// 	max_bits = find_bits(largest);
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		n = 0;
// 		while (n <= largest)
// 		{
// 			if (((vars->a)->pos >> i) & 1)
// 				rotate_a (vars->a);
// 			else

// 			ft_printf("test\n");
// 				push_b(vars->a, vars->b);
// 			n++;
// 		}
// 		while (vars->b)
// 			push_a(vars->a, vars->a);
// 		i++;
// 	}
// }

void	sorting( t_elements *vars)
{
	vars->tot = count_nodes(vars->a);
	if (sorted(&vars->a) == 0 && vars->tot <= 3)
		sort_three(vars);
	else if (sorted(&vars->a) == 0 && vars->tot  <= 5)
		sort_five(vars);
	else if (sorted(&vars->a) == 0)
		radix_five(vars);
	else
	{
		free_stack(vars->a);
		free_stack(vars->b);
	}
}