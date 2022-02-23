/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 13:55:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/22 10:09:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/push_swap.h"

t_numberinfo	get_min_nb_info_in_stack(t_stack *stack)
{
	unsigned int	i;
	t_numberinfo	nb_info;

	nb_info.idx = 0;
	nb_info.nb = stack->stack[0];
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] < nb_info.nb)
		{
			nb_info.nb = stack->stack[i];
			nb_info.idx = i;
		}
		i++;
	}
	if (stack->size / 2 > nb_info.idx)
	{
		nb_info.r = reverse_rotate;
		ft_strlcpy(nb_info.str, "rra\n", 5);
	}
	else
	{
		nb_info.r = rotate;
		ft_strlcpy(nb_info.str, "ra\n", 4);
	}
	return (nb_info);
}

void	order_simple(t_stack *a, t_stack *b)
{
	t_numberinfo	nb_info;

	while (a->size > 1)
	{
		nb_info = get_min_nb_info_in_stack(a);
		while (a->stack[a->size - 1] != nb_info.nb)
		{
			nb_info.r(a);
			ft_putstr_fd(1, nb_info.str);
		}
		push(b, a);
		ft_putstr_fd(1, "pb\n");
	}
	while (b->size > 0)
	{
		push(a, b);
		ft_putstr_fd(1, "pa\n");
	}
}

int	main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	if (ac == 1)
		return (1);
	stack_init_push_swap(&a, &b, ac, av);
	order_simple(&a, &b);
	print_stacks(&a, &b);
}
