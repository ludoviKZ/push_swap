/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzorzit <lzorzit@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:18:07 by lzorzit           #+#    #+#             */
/*   Updated: 2025/03/10 18:44:56 by lzorzit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stak
{
	struct s_stak	*next;
	long			val;
	long			pos;
}				t_stak;

typedef struct s_elements
{
	struct s_stak	*a;
	struct s_stak	*b;
	long int		tot;
	int				largest;
	int				moves;
}				t_elements;

typedef struct s_calcs
{
	int		least;
	int		ret;
	int		pos;
	int		add;
	t_stak	*copya;
}				t_calcs;

void	sort_three(t_elements *vars);
void	sort_five(t_elements *vars);
void	sorting( t_elements *vars);
int		issorted(t_elements *vars);
void	free_stacks(t_elements *vars);
int		find_first(t_stak *head);
int		count_nodes(t_stak *head);
void	print_list(t_stak *head);
t_stak	*make_new_node(int new_value);
void	addnode(t_stak **head, int new_value);
void	setpos(t_stak *head, int link_size);
t_stak	*init_list(int argc, char **argv);
void	free_matrixps(char **arr);
int		allunique(char **matr);
int		isnbr(char *matr);
int		isvalid(int argc, char **argv);
int		count_arg(char **array);
void	swap(t_stak	**stack);
void	swap_a(t_elements	*vars);
void	swap_b(t_elements	*vars);
void	swap_ab(t_elements	*vars);
void	push(t_stak **stack_from, t_stak **stack_to);
void	push_a(t_elements	*vars);
void	push_b(t_elements	*vars);
void	rotate(t_stak **stack);
void	rotate_a(t_elements	*vars);
void	rotate_ab(t_elements	*vars);
void	rotate_b(t_elements	*vars);
void	r_rotate(t_stak **stack);
void	r_rotate_a(t_elements	*vars);
void	r_rotate_b(t_elements	*vars);
void	r_rotate_ab(t_elements	*vars);
void	sort_turk(t_elements *vars);
int		findquickrev(t_stak *to, t_calcs *v);
int		node_pos(t_stak *stack, int i);
int		calcleast(t_stak *from, t_stak *to);
int		findnode(t_stak *stack, int find);
int		nextleast(t_stak *to, int i);
int		smart_rota(t_elements *vars, int pos_next);
int		smart_rotb(t_elements *vars, int pos_next);
int		findquick(t_stak *to, t_calcs *v);
void	bunchmoves(t_elements *vars, int *rota, int *rotb, int push);
#endif