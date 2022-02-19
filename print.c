/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 10:26:15 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/02/18 12:38:20 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>//
#include "push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	unsigned int	i;

	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size - 1;
	while (true)
	{
		if (i < a->size)
			printf("%5d\t", a->stack[i]);
		else
			printf("\t");
		if (i < b->size)
			printf("%5d", b->stack[i]);
		printf("\n");
		if (i == 0)
			break ;
		i--;
	}
	printf("--a--\t--b--\n\n");
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_strlen(str));
}