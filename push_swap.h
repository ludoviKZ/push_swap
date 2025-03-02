

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stak
{
	struct s_stak *next;
	long		val;
	long		pos;
}				t_stak;

typedef struct s_elements
{
	struct s_stak  *a;
	struct s_stak  *b; 
	long int	tot;
	long int	asize;
	long int	bsize;    
}           t_elements;

void	sort_three(t_elements *vars);
void	sort_five(t_elements *vars);
void	sort_turk(t_elements *vars);
void	sorting( t_elements *vars);
int	find_biggest(t_stak *head);
int	find_bits(int n);
int	count_nodes(t_stak *head);
void	print_list(t_stak *head);
t_stak	*make_new_node(int new_value);
void	addnode(t_stak **head, int new_value);
void	setpos(t_stak *head, int link_size);
t_stak	*init_list(int argc, char **argv);
void	free_matrixps(char **arr);
int	allunique(char **matr);
int	isnbr(char *matr);
int isvalid (int argc, char **argv);
int	count_arg(char **array);
void	swap(t_stak	**head);
void	swap_a(t_elements	*vars);
void	swap_b(t_elements	*vars);
void	swap_ab(t_elements	*vars);
void	push(t_stak **stack_from, t_stak **stack_to);
void	push_a(t_elements	*vars);
void	push_b(t_elements	*vars);
void	rotate_cw(t_stak **head);
void	rotate_a(t_elements	*vars);
void	rotate_ab(t_elements	*vars);
void	rotate_b(t_elements	*vars);
void	rotate_ccw(t_stak **head);
void	r_rotate_a(t_elements	*vars);
void	r_rotate_b(t_elements	*vars);
void	r_rotate_ab(t_elements	*vars);

#endif