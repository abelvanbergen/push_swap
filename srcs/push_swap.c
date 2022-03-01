/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 13:55:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/03/01 18:37:40 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/push_swap.h"
#include <stdio.h> //

void	sort_3_numbers(t_stack *a)
{
	if (a->stack[0] < a->stack[1] || a->stack[0] < a->stack[2])
	{
		if (a->stack[1] > a->stack[2])
		{
			ft_putstr_fd(1, "rra\n");
			reverse_rotate(a);
		}
		else
		{
			ft_putstr_fd(1, "ra\n");
			rotate(a);
		}
	}
	if (a->stack[1] < a->stack[2])
	{
		ft_putstr_fd(1, "sa\n");
		swap(a);
	}
}

void	sort_2_numbers(t_stack *a)
{
	if (a->stack[0] < a->stack[1])
	{
		ft_putstr_fd(1, "sa\n");
		swap(a);
	}
}

void	move_to(t_stack *dest, t_stack *srcs)
{
	while (srcs->size > 0)
		push(dest, srcs);
}

static int	ft_pow(unsigned int base, unsigned int exp)
{
	int	nb;

	if (exp == 0)
		return (1);
	nb = base;
	while (exp > 1)
	{
		nb *= base;
		exp--;
	}
	return (nb);
}

void	buildup_stack_3(t_stack *dest, t_stack *srcs, int pow, int topvalue, int last_group)
{
	unsigned int		i;
	int					val;
	const unsigned int	stack_size = srcs->size;

	i = 0;
	while (i < stack_size)
	{
		val = (srcs->stack[srcs->size - 1] / pow) % 3;
		if (val == topvalue)
			rotate(srcs);
		else if (val == 1)
			push(dest, srcs);
		else
			push_bottum(dest, srcs);
		i++;
	}
	while (srcs->size > 0)
	{
		if ()
	}
		push(dest, srcs);
}

void	radix_sort_3(t_stack *a, t_stack *b)
{
	const int	biggest_nb = a->size - 1;
	int			exp;

	exp = 0;
	while (biggest_nb / ft_pow(3, exp) != 0)
	{
		if (exp % 2 == 0)
			buildup_stack_3(b, a, ft_pow(3, exp), 2);
		else
			buildup_stack_3(a, b, ft_pow(3, exp), 0);
		exp++;
	}
	if (a->size == 0)
		move_to(a, b);
}

void	radix_sort_2(t_stack *a, t_stack *b)
{
	const unsigned int	stack_size = a->size;
	unsigned int		pow;
	unsigned int		i;
	int					val;
	unsigned int		exp;

	exp = 0;
	pow = ft_pow(2, exp);
	while ((stack_size - 1) / pow != 0)
	{
		i = 0;
		while (i < stack_size)
		{
			val = (a->stack[a->size - 1] / pow) % 2;
			if (val == 0)
				push(b, a);
			else
				rotate(a);
			i++;
		}
		while (b->size > 0)
			push(a, b);
		exp++;
		pow = ft_pow(2, exp);
	}
}

int	main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	if (ac == 1)
		return (1);
	stack_init_push_swap(&a, &b, ac, av);
	a.name = 'a';
	b.name = 'b';
	if (a.size == 1)
		return (0);
	else if (a.size == 2)
		sort_2_numbers(&a);
	else if (a.size == 3)
		sort_3_numbers(&a);
	else
		radix_sort_3(&a, &b);
}
