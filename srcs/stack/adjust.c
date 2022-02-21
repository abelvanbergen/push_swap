/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   adjust.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 17:29:06 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/21 17:31:19 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	add_nb_to_stack(t_stack *stack, int nb)
{
	stack->stack[stack->size] = nb;
	stack->size++;
}

void	add_nb_to_stack_on_idx(t_stack *stack, int nb, unsigned int idx)
{
	stack->stack[idx] = nb;
	stack->size++;
}

void	add_new_nb_to_stack(t_stack *stack, int nb)
{
	if (isDuplicate(stack, nb))
		exit_with_message(1, "There is a duplicate");
	add_number_to_stack(stack, nb);
}

void	remove_nb_from_stack(t_stack *stack, unsigned int idx)
{
	ft_memmove(stack->stack + idx, stack->stack + 1, stack->size - idx);
	stack->size--;
}
