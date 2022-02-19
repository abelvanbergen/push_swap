/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 14:07:01 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/19 17:48:17 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdbool.h>

static bool	isDuplicate(t_stack *stack, int nb)
{
	unsigned int	i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->stack[i] == nb)
			return (true);
		i++;
	}
	return (false);
}

void	add_number_to_stack(t_stack *stack, int nb)
{
	stack->stack[stack->size] = nb;
	stack->size++;
}

void	add_new_number_to_stack(t_stack *stack, int nb)
{
	if (isDuplicate(stack, nb))
		exit_with_message(1, "There is a duplicate");
	add_number_to_stack(stack, nb);
}

void	stack_init(t_stack *a, t_stack *b, int ac, char **av)
{
	const size_t	stacksize = ac - 1;

	a->stack = malloc_check(malloc(sizeof(int) * stacksize));
	a->capacity = stacksize;
	a->size = 0;
	ac--;
	while (ac > 0)
	{
		if (!ft_isnumber(av[ac]))
			exit_with_message(1, "not a number");
		add_number_to_stack(a, ft_basic_itoa(av[ac]));
		ac--;
	}
	b->stack = malloc_check(malloc(sizeof(int) * stacksize));
	b->capacity = stacksize;
	b->size = 0;
}
