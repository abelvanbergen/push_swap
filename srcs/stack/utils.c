/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:28:13 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/22 19:05:33 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "../../includes/push_swap.h"

unsigned int	get_idx_nb(t_stack *stack, int nb)
{
	unsigned int	i;

	i = 0;
	while (true)
	{
		if (nb == stack->stack[i])
			return (i);
		i++;
	}
	return (0);
}

int	get_max_nb(t_stack *stack)
{
	unsigned int	i;
	int				max;

	max = stack->stack[0];
	i = 1;
	while (i < stack->size)
	{
		if (max < stack->stack[i])
			max = stack->stack[i];
		i++;
	}
	return (max);
}

bool	is_duplicate(t_stack *stack, int nb)
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
