/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 14:07:01 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/22 19:18:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>
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
	print_stacks(location, dest);
	nb = location->capacity - 1;
	printf("begin loop\n");
	while (order->size > 0)
	{
		print_stacks(dest, order);
		max_nb = get_max_nb(order);
		idx = get_idx_nb(location, max_nb);
		printf("max_nb: %i\nnb %u -> loc %u\n", max_nb, nb, idx);
		add_nb_to_stack_on_idx(dest, nb, idx);
		nb--;
		remove_nb_from_stack(order, get_idx_nb(order, max_nb));
	}
}

static void	stack_init_with_arguments(t_stack *stack, unsigned int len, char **av)
{
	stack_init_empty(stack, len);
	while (len > 0)
	{
		if (!ft_isnumber(av[len]))
			exit_with_message(1, "not a number");
		add_new_nb_to_stack(stack, ft_basic_itoa(av[len]));
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
	print_stacks(&location, &order);
	stack_init_with_basic_values(a, &location, &order);
	print_stacks(&location, &order);
	print_stacks(&location, a);
	exit(1);
	// stack_init_empty(b, a->capacity);
	// print_stacks(a, b);
}

void	stack_init_checker(t_stack *a, t_stack *b, int ac, char **av)
{
	stack_init_with_arguments(a, ac - 1, av);
	stack_init_empty(b, a->capacity);
}
