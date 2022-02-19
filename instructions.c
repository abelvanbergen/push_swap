/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 10:34:06 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/02/18 12:33:40 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack->size <= 1)
		return ;
	temp = stack->stack[stack->size - 1];
	stack->stack[stack->size - 1] = stack->stack[stack->size - 2];
	stack->stack[stack->size - 2] = temp;
}

void	push(t_stack *dest, t_stack *src)
{
	if (src->size == 0)
		return ;
	add_number_to_stack(dest, src->stack[src->size - 1]);
	src->size--;
}

void	rotate(t_stack *stack)
{
	int	temp;

	if (stack->size <= 1)
		return ;
	temp = stack->stack[stack->size - 1];
	ft_memmove(stack->stack + 1, stack->stack, sizeof(int) * (stack->size - 1));
	stack->stack[0] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;

	if (stack->size <= 1)
		return ;
	temp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, sizeof(int) * (stack->size - 1));
	stack->stack[stack->size - 1] = temp;
}