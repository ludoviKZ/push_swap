#include "push_swap.h"

void bunchswap(t_elements *vars, int *rota, int *rotb)
{
	while (rota[0] != 0 && rota[0] > 0)
	{
		rotate_a(vars);
		rota[0]--;
	}
	while (rota[0] != 0 && rota[0] < 0)
	{
		r_rotate_a(vars);
		rota[0]++;
	}
	while (rotb[0] != 0 && rotb[0] > 0)
	{
		rotate_b(vars);
		rotb[0]--;
	}
	while (rotb[0] != 0 && rotb[0] < 0)
	{
		r_rotate_b(vars);
		rotb[0]++;
	}
}

void bunchmoves(t_elements *vars, int *rota, int *rotb, int push)
{
	if (rota[0] > 0 && rotb[0] > 0)
	{
		while(rota[0] > 0 && rotb[0] > 0)
		{
			rotate_ab(vars);
			rota[0] --;
			rotb[0] --;
		}
	}
	else if (rota[0] < 0 && rotb[0] < 0)
	{
		while(rota[0] < 0 && rotb[0] < 0)
		{
			r_rotate_ab(vars);
			rota[0] ++;
			rotb[0] ++;
		}
	}
	bunchswap(vars, rota, rotb);
	if (push == 'b')
		push_b(vars);
	else
		push_a(vars);
	rotb[0] = 0;
	rota[0] = 0;
}

int	smart_rota(t_elements *vars,int pos_next)
{
	int		ret;
	int		stack_size;

	ret = 0;
	stack_size = count_nodes(vars->a);
	if (pos_next <= stack_size/2)
	{
		while (pos_next != 0)
		{
			pos_next --;
			ret ++;
		}
	}
	else
	{
		while ((stack_size - pos_next) != 0)
		{
			ret --;
			pos_next ++;
		}
	}
	return (ret);
}

int	smart_rotb(t_elements *vars,int pos_next)
{
	int		ret;
	int		stack_size;

	ret = 0;
	stack_size = count_nodes(vars->b);
	if (pos_next <= stack_size/2)
	{
		while (pos_next != 0)
		{
			pos_next --;
			ret ++;
		}
	}
	else
	{
		while ((stack_size - pos_next) != 0)
		{
			ret --;
			pos_next ++;
		}
	}
	return(ret);
}