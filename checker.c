/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 12:49:32 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/02/18 13:18:18 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	isSorted(t_stack *stack)
{
	unsigned int i;

	if (stack->size == 0)
		return true;
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] > stack->stack[i - 1])
			return false;
		i++;
	}
	return true;
}

int  main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**instructions;

	if (ac == 1)
		return ;
	stack_init(&a, &b, ac, av);
	instructions =  get_instructions();
}