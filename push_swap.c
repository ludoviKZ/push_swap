#include "push_swap.h"

// int	issorted(t_stak	**a)
// {
// 	t_stak	*tmp;

// 	tmp = *a;
// 	while (tmp && tmp.next)
// 	{
// 		if (tmp.pos > tmp.next.pos)
// 			return (0);
// 		tmp = tmp.next;
// 	}
// 	return (1);
// }

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

void	free_stack(t_stak *head)
{
	t_stak	*tmp;

	while (head)
	{
		tmp = head;
		head = (head)->next;
		free(tmp);
	}
}

int main (int argc, char **argv)
{
	t_elements	vars;


    if (isvalid(argc, argv) == 0)
        return (ft_printf("imput invalid"), 0);
	vars.a = init_list(argc, argv);
	vars.b = 0;
	setpos(vars.a, count_nodes(vars.a));
	print_list(vars.a);
	sorting(&vars);
	// freevars(&vars.a);
	// freevars(&vars.b);
	return(0);
}