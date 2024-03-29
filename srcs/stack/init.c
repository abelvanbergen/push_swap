/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 14:07:01 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/03/28 20:08:06 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>
#include <limits.h> //
#include <stdio.h> //

void	stack_init_empty(t_stack *stack, unsigned int capacity)
{
	stack->size = 0;
	stack->capacity = capacity;
	stack->stack = malloc_check(malloc(sizeof(int) * capacity));
}

static void	stack_init_with_basic_values(t_stack *dest, t_stack *location, t_stack *order)
{
	int				max_nb;
	unsigned int	idx;
	unsigned int	nb;

	stack_init_empty(dest, location->capacity);
	nb = location->capacity - 1;
	while (order->size > 0)
	{
		max_nb = get_max_nb(order);
		idx = get_idx_nb(location, max_nb);
		add_nb_to_stack_on_idx(dest, nb, idx);
		nb--;
		remove_nb_from_stack(order, get_idx_nb(order, max_nb));
	}
}

static void	stack_init_with_arguments(t_stack *stack, unsigned int len, char **av)
{
	int	nb;

	stack_init_empty(stack, len);
	while (len > 0)
	{
		if (!ft_isnumber(av[len]))
			exit_with_message(1, "not a number");
		if (!ft_basic_atoi(av[len], &nb))
			exit_with_message(1, "to big for a interger");
		add_new_nb_to_stack(stack, nb);
		len--;
	}
}

void	stack_init_push_swap(t_stack *a, t_stack *b, int ac, char **av)
{
	t_stack	location;
	t_stack	order;

	(void)a;
	(void)b;
	stack_init_with_arguments(&location, ac - 1, av);
	stack_cpy(&order, &location);
	stack_init_with_basic_values(a, &location, &order); //memorie_leak
	stack_init_empty(b, a->capacity);
}

void	stack_init_checker(t_stack *a, t_stack *b, int ac, char **av)
{
	stack_init_with_arguments(a, ac - 1, av);
	stack_init_empty(b, a->capacity);
}
