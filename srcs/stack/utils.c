/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:28:13 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/21 17:28:49 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

unsigned int	get_idx_max_nb(t_stack *stack)
{
	unsigned int	i;
	unsigend int	max_i;
	int				max;

	max_i = 1;
	max = stack->stack[i];
	i = 1;
	while (i < stack->size)
	{
		if (max < stack->stack[i])
		{
			max_i = i;
			max = stack->stack[i];
		}
		i++;
	}
	return (max_i);
}

bool	isDuplicate(t_stack *stack, int nb)
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
