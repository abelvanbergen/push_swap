/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 14:07:01 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/21 17:36:00 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>

static void	stack_init_empty(t_stack *stack, unsigned int capacity)
{
	stack->size = 0;
	stack->capacity = capacity;
	stack->stack = malloc_check(malloc(sizeof(int) * capacity));
}

static void	stack_init_with_basic_values(t_stack *dest, t_stack *src)
{
	unsigned int	idx;
	unsigned int	nb;

	init_empty_stack(dest, src->capacity);
	nb = src->capacity - 1;
	while (src->size > 0)
	{
		idx = get_idx_max_nb(src);
		add_nb_to_stack_on_idx(dest, nb, idx);
		nb--;
		remove_element_stack(src, idx);
	}
}

static void	stack_init_with_arguments(t_stack *stack, unsigned int len, char **av)
{
	init_empty_stack(stack, len);
	while (len > 0)
	{
		if (!ft_isnumber(arg[len]))
			exit_with_message(1, "not a number");
		add_new_number_to_stack(a, ft_basic_itoa(arg[len]));
		len--;
	}
}

void	stack_init_push_swap(t_stack *a, t_stack *b, int ac, char **av)
{
	t_stack	temp;

	stack_init_with_arguments(&temp, ac - 1, av);
	stack_init_with_basic_values(a, &temp);
	stack_init_empty(b);
}

void	stack_init_checker(t_stack *a, t_stack *b, int ac, char **av)
{
	stack_init_with_arguments(&a, ac - 1, av);
	stack_init_empty(b);
}
