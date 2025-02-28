void	free_matrix(char **arr)
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

int	allunique(char **matr)
{
	int	i;
	int	n;
	int	len;

	i = 0;
	len = count_arg(matr);
	while (i < len)
	{
		n = i + 1;
		while (n < len)
		{
			if (ft_atoi(matr[i]) == ft_atoi(matr[n]))
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int	isnbr(char *matr)
{
	int	i;

	i = 0;
	if (matr[i] == '-')
		i++;
	while (matr[i])
	{
		if (ft_isdigit(matr[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int isvalid (int argc, char **argv)
{
	int		i;
	long	nmbr;
	char	**matr;

	i = 0;
	if (argc == 2)
		matr = ft_split(argv[1], ' ');
	else
		matr = argv + 1;
    if (allunique(matr) == 1)
			return (0);
	while (matr[i] != 0)
	{
		nmbr = ft_atoi(matr[i]);
		if (nmbr < INT_MIN || nmbr > INT_MAX)
            return (0);
		if (!isnbr(matr[i]) == 1)
           return (0);
		i++;
	}
	if (argc == 2)
		return (free_matrix(matr), 1);
}