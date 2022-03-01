/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 10:34:06 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/03/01 16:32:14 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

void	swap(t_stack *stack)
{
	int	temp;

	printf("s%c\n", stack->name);
	if (stack->size <= 1)
		return ;
	temp = stack->stack[stack->size - 1];
	stack->stack[stack->size - 1] = stack->stack[stack->size - 2];
	stack->stack[stack->size - 2] = temp;
}

void	push(t_stack *dest, t_stack *src)
{
	printf("p%c\n", dest->name);
	if (src->size == 0)
		return ;
	add_nb_to_stack(dest, src->stack[src->size - 1]);
	src->size--;
}

void	rotate(t_stack *stack)
{
	int	temp;

	printf("r%c\n", stack->name);
	if (stack->size <= 1)
		return ;
	temp = stack->stack[stack->size - 1];
	ft_memmove(stack->stack + 1, stack->stack, sizeof(int) * (stack->size - 1));
	stack->stack[0] = temp;
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;

	printf("rr%c\n", stack->name);
	if (stack->size <= 1)
		return ;
	temp = stack->stack[0];
	ft_memmove(stack->stack, stack->stack + 1, sizeof(int) * (stack->size - 1));
	stack->stack[stack->size - 1] = temp;
}
