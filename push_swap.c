int	issorted(t_elements	*vars)
{
	t_stak	*tmp;

	tmp = vars.a;
	while (tmp != 0 && tmp->next != 0)
	{
		if (tmp->pos > tmp->next->pos)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	free_matrix(char **mat)
{
	int	i;

	i = 0;
	while (mat)
		i++;
	while (i > 0)
	{
		i --;
		if (mat[i])
			free(mat[i]);
	}
	free(mat);
}

int main (int argc, char **argv)
{
	t_elements	vars;


    if (isvalid(argc, argv) == 0)
        return (ft_printf("imput invalid"), 0);
	vars.a = init_list(argc, argv)
	vars.b = 0;
	setpos(&vars.a, count_nodes(vars.a));
	sorting(&vars);
	freevars(&vars);
	return(0);
}