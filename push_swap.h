

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stak
{
	struct s_stak *next;
	long		val;
	long		pos;
}				t_stak;

dypedef struct s_elements
{
	struct s_stak  a;
	struct s_stak  b; 
	long int	tot;
	long int	asize;
	long int	bsize;    
}           t_elements;
