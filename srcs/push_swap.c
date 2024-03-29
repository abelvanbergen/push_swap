/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 13:55:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2023/01/22 21:10:01 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/push_swap.h"
#include <stdio.h> //

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

int	divide_in_three(t_stack *dest, t_stack *srcs, int pow, int topvalue)
{
	unsigned int		i;
	int					val;
	const unsigned int	stack_size = srcs->size;
	int					amount_middle;			

	i = 0;
	amount_middle = 0;
	while (i < stack_size)
	{
		val = (srcs->stack[srcs->size - 1] / pow) % 3;
		if (val == topvalue)
			rotate(srcs);
		else if (val == 1)
		{
			push(dest, srcs);
			amount_middle++;
		}
		else
			push_bottum(dest, srcs);
		i++;
	}
	return (amount_middle);
}

void	place_back(t_stack *dest, t_stack *srcs, int amount_middle)
{
	while (amount_middle > 0)
	{
		push(dest, srcs);
		amount_middle--;
	}
	while (srcs->size > 0)
	{
		reverse_rotate(srcs);
		push(dest, srcs);
	}
}

void	radix_sort_3_new(t_stack *a, t_stack *b) // AVG 100->1341 500->7371
{
	const int	biggest_nb = a->size - 1;
	int			exp;
	int			amount_middle;

	exp = 0;
	while (biggest_nb / ft_pow(3, exp) != 0)
	{
		amount_middle = divide_in_three(b, a, ft_pow(3, exp), 2);
		place_back(a, b, amount_middle);
		exp++;
	}
}

void	buildup_stack_3_new_new(t_stack *dest, t_stack *srcs, int pow, int bottum_value)
{
	unsigned int		i;
	int					val;
	unsigned int		stack_size;

	i = 0;
	stack_size = srcs->size;
	while (i < stack_size)
	{
		val = (srcs->stack[srcs->size - 1] / pow) % 3;
		if (val == bottum_value)
			push(dest, srcs);
		else
			rotate(srcs);
		i++;
	}
	i = 0;
	stack_size = srcs->size;
	while (i < stack_size)
	{
		val = (srcs->stack[srcs->size - 1] / pow) % 3;
		if (val == 1)
			push(dest, srcs);
		else
			rotate(srcs);
		i++;
	}
	while (srcs->size > 0)
		push(dest, srcs);
}

int		get_amount_of_splits(int biggest_nb)
{
	int		exp;

	exp = 0;
	while (biggest_nb / ft_pow(3, exp) != 0)
		exp++;
	return (exp);
}

bool	is_reversed_sorted(t_stack *stack)
{
	unsigned int	i;

	i = 1;
	if (stack->size == 1)
		return (true);
	while (i < stack->size)
	{
		if (stack->stack[i] < stack->stack[i - 1])
			return (false);
		i++;
	}
	return (true);
}

bool	is_sorted(t_stack *stack)
{
	unsigned int	i;

	i = 1;
	if (stack->size == 1)
		return (true);
	while (i < stack->size)
	{
		if (stack->stack[i] > stack->stack[i - 1])
			return (false);
		i++;
	}
	return (true);
}

void	last_turn(t_stack *a, t_stack *b, int pow)
{
	int	stack_size;
	int	val;
	int	i;

	i = 0;
	stack_size = a->size;
	while (i < stack_size)
	{
		val = (a->stack[a->size - 1] / pow) % 3;
		if (val == 0)
			push(b, a);
		else
			rotate(a);
		if (a->stack[0] == stack_size - 1 && is_sorted(a))
			return ;
		i++;
	}
	i = 0;
	stack_size = a->size;
	while (i < stack_size)
	{
		val = (a->stack[a->size - 1] / pow) % 3;
		if (val == 1)
			push(b, a);
		else
			rotate(a);
		if (a->stack[0] == stack_size - 1 && is_sorted(a))
			return ;
		i++;
	}
}

void	radix_sort_3_new_new(t_stack *a, t_stack *b) // AVG 100->866 500->6222
{
	int		max_exp;
	bool	sorted;
	int		exp;

	sorted = true;
	max_exp = get_amount_of_splits(a->size - 1);
	if (max_exp % 2 == 1)
	{
		sorted = false;
		max_exp--;
	}
	exp = 0;
	while (exp < max_exp)
	{
		buildup_stack_3_new_new(b, a, ft_pow(3, exp), 0);
		exp++;
		buildup_stack_3_new_new(a, b, ft_pow(3, exp), 2);
		exp++;
	}
	if (sorted == false)
	{
		last_turn(a, b, ft_pow(3, exp));
		while (b->size > 0)
			push(a, b);
	}
}

void	radix_sort_2(t_stack *a, t_stack *b) // AVG 100->1084 500->6784
{
	const unsigned int	stack_size = a->size;
	unsigned int		pow;
	unsigned int		i;
	int					val;
	unsigned int		exp;

	exp = 0;
	pow = ft_pow(2, exp);
	while (stack_size > pow)
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

void	return_stack_b(t_stack *a, t_stack *b)
{
	while (b->size > 0)
		push(a, b);
}

void	last_turn_ultra(t_stack *a, t_stack *b, unsigned int pow)
{
	unsigned int		len_b;
	unsigned int		len_a;
	unsigned int		i;
	int					val;

	len_b = b->size;
	i = 0;
	while (i < len_b)
	{
		if (is_sorted(a) && is_sorted(b))
			return (return_stack_b(a, b));
		val = (b->stack[b->size - 1] / pow) % 2;
		if (val == 0)
			rotate(b);
		else
			push(a, b);
		i++;
	}
	i = 0;
	len_a = a->size;
	while (i < len_a)
	{
		if (is_sorted(a) && is_sorted(b))
			return (return_stack_b(a, b));
		val = (a->stack[a->size - 1] / pow) % 2;
		if (val == 1)
			rotate(a);
		else
			push(b, a);
		i++;
	}
}

void	radix_sort_ultra(t_stack *a, t_stack *b)
{
	const unsigned int	stack_size = a->size;
	const unsigned int	base = 2;
	unsigned int		pow;
	unsigned int		len_b;
	unsigned int		len_a;
	unsigned int		i;
	int					val;

	pow = 1;
	while (stack_size / 2 > pow)
	{
		len_b = b->size;
		i = 0;
		while (i < len_b)
		{
			val = (b->stack[b->size - 1] / pow) % 2;
			if (val == 0)
				rotate(b);
			else
				push(a, b);
			i++;
		}
		i = 0;
		len_a = a->size;
		while (i < len_a)
		{
			val = (a->stack[a->size - 1] / pow) % 2;
			if (val == 1)
				rotate(a);
			else
				push(b, a);
			i++;
		}
		pow *= base;
	}
	last_turn_ultra(a, b, pow);
}

void	set_back_b(t_stack *a, t_stack *b, int base, int pow, bool last_time)
{
	int				to_move;
	int				val;
	unsigned int	len;

	to_move = base - 2;
	while (to_move > 0)
	{
		len = b->size;
		while (len > 0)
		{
			if (last_time == true && is_reversed_sorted(b))
				return (return_stack_b(a, b));
			val = (b->stack[b->size - 1] / pow) % base;
			if (val == to_move)
				push(a, b);
			else
				rotate(b);
			len--;
		}
		to_move--;
	}
	return_stack_b(a, b);
}

void	radix_sort_base(t_stack *a, t_stack *b, int base)
{
	const unsigned int	stack_size = a->size;
	unsigned int		pow;
	unsigned int		i;
	int					val;

	pow = 1;
	while (stack_size > pow)
	{
		i = 0;
		while (i < stack_size)
		{
			val = (a->stack[a->size - 1] / pow) % base;
			if (val == base - 1)
				rotate(a);
			else
				push(b, a);
			i++;
		}
		set_back_b(a, b, base, pow, stack_size / base > pow);
		pow *= base;
	}
}

void radix_sort_4(t_stack *a, t_stack *b, int pow)
{
	const unsigned int	stack_size = a->size;
	unsigned int	top;
	unsigned int	bottum;
	unsigned int	i;
	int				val;

	top = 0;
	i = 0;
	bottum = 0;
	// printf("hij komt er wel in");
	while (i < stack_size) {
		val = (a->stack[a->size - 1] / pow) % 4;
		if (val == 2) {
			rotate(a);
		}
		else {
			top += 1;
			push(b, a);
		}
		if (val == 3) {
			bottum += 1;
			rotate(b);
		}
		i++;
	}
	top -= bottum;
	i = 0;
	while (i < top) {
		val = (b->stack[b->size - 1] / pow) % 4;
		if (val == 1) {
			push(a, b);
		} else {
			rotate(b);
		}
		i++;
	}
	i = 0;
	while (i < bottum) {
		push(a, b);
		rotate(a);
		i++;
	}
	while (b->size) {
		push(a, b);
	}
	pow *= 5;
}

void radix_sort_5(t_stack *a, t_stack *b)
{
	const unsigned int	stack_size = a->size;
	unsigned int	top;
	unsigned int	top_left;
	unsigned int	bottum;
	unsigned int	pow;
	unsigned int	i;
	int				val;

	pow = 1;
	while (stack_size > pow) {
		if (stack_size == pow * 4)
			return radix_sort_4(a, b, pow);
		top = 0;
		i = 0;
		bottum = 0;
		while (i < stack_size) {
			val = (a->stack[a->size - 1] / pow) % 5;
			if (val == 2) {
				rotate(a);
			}
			else {
				top += 1;
				push(b, a);
			}
			if (val == 3 || val == 4) {
				bottum += 1;
				rotate(b);
			}
			i++;
		}
		top -= bottum;
		i = 0;
		top_left = 0;
		while (i < top) {
			val = (b->stack[b->size - 1] / pow) % 5;
			if (val == 1) {
				push(a, b);
			} else {
				top_left++;
				rotate(b);
			}
			i++;
		}
		i = 0;
		while (i < bottum) {
			val = (b->stack[b->size - 1] / pow) % 5;
			if (val == 3) {
				push(a, b);
				rotate(a);
			} else {
				rotate(b);
			}
			i++;
		}
		i = 0;
		while (i < top_left) {
			push(a, b);
			i++;
		}
		while (b->size) {
			push(a, b);
			rotate(a);
		}
		pow *= 5;
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
	else if (a.size == 4)
		sort_4_numbers(&a, &b);
	else if (a.size == 5)
		sort_5_numbers(&a, &b);
	else
		radix_sort_5(&a, &b);
}
