/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_instructions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 11:43:34 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/25 13:28:03 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	double_swap(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}

void	double_rotate(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
}

void	double_reverse_rotate(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}

void	push_bottum(t_stack *dest, t_stack *srcs)
{
	push(dest, srcs);
	rotate(dest);
}
