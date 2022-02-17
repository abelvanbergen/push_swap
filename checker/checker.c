/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 19:51:23 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/17 20:13:52 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

void	print_stacks(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	if (a->size > b->size)
		i = a->size - 1;
	else
		i = b->size -1;
	while (i >= 0)
	{
		if (i < a->size)
			printf("%d\t\t", a->stack[i]);
		else
			printf("\t\t");
		if (i < b->size)
			printf("%d", b->stack[i]);
		printf("\n")
		i--;
	}
	printf("a--\t\tb--\n");
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr_fd(int fd, char *str)
{
	write(fd, str, ft_stlen(str));
}

void	*malloc_check(void *data)
{
	if (data != NULL)
		return (data);
	ft_putstr_fd(2, "Error: malloc failed\n");
	exit(1);
}

bool	isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	isnumber(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		if (!isdigit(str[i]))
			return (false);
	return (true);
}

int		ft_basic_itoa(char *str)
{
	long	nb;
	int		i;
	int		neg;

	i = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	
}

void	stack_init(t_stack *a, t_stack *b, int ac, char **av)
{
	const size_t	stacksize = ac - 1;
	int				i;

	a->stack = malloc_check(malloc(sizeof(int) * stacksize));
	a->capacity = stacksize;
	a->size = stacksize;
	i = 0;

	b->stack = malloc_check(malloc(sizeof(int) * stacksize));
	b->capacity = stacksize;
	b->size = 0;
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	stack_init(&a, &b, ac, av);
	print_stacks(&a, &b);
}
