/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 19:51:23 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/18 13:14:01 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a, &b, ac, av);
	print_stacks(&a, &b);
	push(&b, &a);
	print_stacks(&a, &b);
	push(&b, &a);
	print_stacks(&a, &b);
	swap(&a);
	swap(&b);
	print_stacks(&a, &b);
	push(&b, &a);
	print_stacks(&a, &b);
	rotate(&a);
	reverse_rotate(&b);
	print_stacks(&a, &b);
}
