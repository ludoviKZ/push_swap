#include "push_swap.h"

int	count_nodes(t_stak *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	print_list(t_stak *head)
{
	t_stak	*current;
	int		i;

	current = head;
	i = 0;
	while (current != NULL)
	{
		ft_printf("node: %d: %d	pos: %d\n", i, current->val, current-> pos);
		i++;
		current = current->next;
	}
}

t_stak	*make_new_node(int new_value)
{
	t_stak	*new_node;

	new_node = ft_calloc(1, sizeof(t_stak));
	if (!new_node)
		return (NULL);
	new_node->val = new_value;
	new_node->pos = 0;
	new_node->next = NULL;
	return (new_node);
}

void	addnode(t_stak **head, int new_value)
{
	t_stak	*new_node;
	t_stak	*current;

	if (*head == NULL)
	{
		*head = make_new_node(new_value);
		return ;
	}
	current = *head;	
	while (current->next != NULL)
	{
		current = current->next;
	}
	new_node = make_new_node(new_value);
	current->next = new_node;
}

void	setpos(t_stak *head, int link_size)
{
	t_stak	*biggest;
	t_stak	*tmp;

	while (link_size-- > 0)
	{
		biggest = NULL;
		tmp = head;
		while (tmp)
		{
			if (!tmp->pos && (biggest == NULL
					|| tmp->val > biggest->val))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->pos = link_size;
	}
}

t_stak	*init_list(int argc, char **argv)
{
	t_stak	*stack_a;
	char	**matr;
	int		i;

	i = 0;
	stack_a = 0;
	if (argc == 2)
		matr = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		matr = argv;
	}
	while (matr[i] != 0)
	{
		addnode(&stack_a, ft_atoi(matr[i]));
		i++;
	}
	if (argc == 2)
		free_matrixps(matr);
	return (stack_a);
}