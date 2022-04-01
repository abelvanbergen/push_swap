/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/01 13:07:50 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/01 13:11:20 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_2_numbers(t_stack *a)
{
	if (a->stack[0] < a->stack[1])
		swap(a);
}

void	sort_3_numbers(t_stack *a)
{
	if (a->stack[0] < a->stack[1] || a->stack[0] < a->stack[2])
	{
		if (a->stack[1] > a->stack[2])
			reverse_rotate(a);
		else
			rotate(a);
	}
	if (a->stack[1] < a->stack[2])
		swap(a);
}

void	sort_4_numbers(t_stack *a, t_stack *b)
{
	while (a->stack[a->size - 1] != 0)
		rotate(a);
	push(b, a);
	sort_3_numbers(a);
	push(a, b);
}

void	sort_5_numbers(t_stack *a, t_stack *b)
{
	while (a->stack[a->size - 1] != 0 && a->stack[a->size - 1] != 1)
		rotate(a);
	push(b, a);
	while (a->stack[a->size - 1] != 0 && a->stack[a->size - 1] != 1)
		rotate(a);
	push(b, a);
	sort_3_numbers(a);
	if (b->stack[0] > b->stack[1])
		rotate(b);
	push(a, b);
	push(a, b);
}