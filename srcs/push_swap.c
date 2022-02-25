/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/19 13:55:19 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/25 17:36:21 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../includes/push_swap.h"

// void	split_first_bucket(t_stack *dest, t_stack *srcs, unsigned int len, int div)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		if (srcs->stack[srcs->size - 1] >= div)
// 		{
// 			write(1, "pb\n", 3);
// 			push(dest, srcs);
// 		}
// 		else
// 		{
// 			write(1, "pb\nrb\n", 6);
// 			push_bottum(dest, srcs);
// 		}
// 		i++;
// 	}
// }

// void	move_bucket_to_top(t_stack *stack, unsigned int size)
// {
// 	unsigned int	i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		write(1, "rrb\n", 4);
// 		reverse_rotate(stack);
// 		i++;
// 	}
// }

// void	split_not_first_bucket(t_stack *dest, t_stack *srcs, unsigned int len, int div)
// {
// 	split_first_bucket(dest, srcs, len, div);
// 	move_bucket_to_top(dest, 5);
// }

void	set_bucket_borders(t_2int borders, unsigned int size, unsigned int start)
{
	
}

void	bucket_info_init(t_bucket_info *obj)
{
	unsigned int	i;
	t_2int			*new_borders;

	new_borders = malloc_check(malloc(sizeof(t_2int) * (obj->groups)));
	i = 0;
	while (i < obj->groups)
	{
		
	}
}

void	split_buckets(t_bucket_info bucket_info, t_stack *dest, t_stack *srcs)
{
	
}

// void	split_first_time_3(t_stack *dest, t_stack *srcs)
// {
// 	t_2int	borders;

// 	borders = get_boarders_bucket();
// }

int	main(int ac, char **av)
{
	t_stack a;
	t_stack b;

	if (ac == 1)
		return (1);
	stack_init_push_swap(&a, &b, ac, av);
	print_stacks(&a, &b);
	split_first_bucket(&b, &a, a.size, a.size / 2);
	print_stacks(&a, &b);
	split_first_bucket(&a, &b, b.size / 2, 15);
	print_stacks(&a, &b);
	split_not_first_bucket(&a, &b, b.size, 5);
	print_stacks(&a, &b);
}
