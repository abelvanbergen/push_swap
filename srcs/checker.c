/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 12:49:32 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/02/19 14:46:19 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdbool.h>
#include <stdio.h> //

#define BUFFER_SIZE 10

bool	is_sorted(t_stack *stack)
{
	unsigned int	i;

	if (stack->size == 0)
		return (true);
	i = 1;
	while (i < stack->size)
	{
		if (stack->stack[i] > stack->stack[i - 1])
			return (false);
		i++;
	}
	return (true);
}

char	*read_instructions(void)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*line;

	line = ft_strdup("");
	if (line == NULL)
		return (NULL);
	while (true)
	{
		bytes_read = read(0, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		if (bytes_read == 0)
			return (line);
		if (bytes_read < 0)
			return (NULL);
		line = ft_strjoin_and_free_s1(line, buf);
		if (line == NULL)
			return (NULL);
	}
}

char	**get_instructions()
{
	char	*str;
	char	**array;

	str = read_instructions();
	if (str == NULL)
		return (NULL);
	array = ft_split(str, '\n');
	free(str);
	return (array);
}

void	exe(char **instructions, t_stack *a, t_stack *b)
{
	size_t	i;

	i = 0;
	while (instructions[i] != NULL)
	{
		print_stacks(a, b);
		if (ft_strncmp("sa", instructions[i], 3) == 0)
			swap(a);
		else if (ft_strncmp("sb", instructions[i], 3) == 0)
			swap(b);
		else if (ft_strncmp("ss", instructions[i], 3) == 0)
			double_swap(a, b);
		else if (ft_strncmp("pa", instructions[i], 3) == 0)
			push(a, b);
		else if (ft_strncmp("pb", instructions[i], 3) == 0)
			push(b, a);
		else if (ft_strncmp("ra", instructions[i], 3) == 0)
			rotate(a);
		else if (ft_strncmp("rb", instructions[i], 3) == 0)
			rotate(b);
		else if (ft_strncmp("rr", instructions[i], 3) == 0)
			double_rotate(a, b);
		else if (ft_strncmp("rra", instructions[i], 4) == 0)
			reverse_rotate(a);
		else if (ft_strncmp("rrb", instructions[i], 4) == 0)
			reverse_rotate(b);
		else if (ft_strncmp("rrr", instructions[i], 4) == 0)
			double_reverse_rotate(a, b);
		else
			exit_with_message(1, "instruction unknown");
		i++;
	}
	print_stacks(a, b);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	char	**instructions;

	if (ac == 1)
		return (1);
	stack_init(&a, &b, ac, av);
	instructions = get_instructions();
	if (instructions == NULL)
		return (1);
	exe(instructions, &a, &b);
	if (b.size == 0 && is_sorted(&a))
		ft_putstr_fd(1, "OK\n");
	else
		ft_putstr_fd(1, "KO\n");
	return (0);
}
