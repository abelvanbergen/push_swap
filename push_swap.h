/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 19:51:51 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/18 12:37:47 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_stack
{
	int				*stack;
	unsigned int	size;
	unsigned int	capacity;
}					t_stack;

void	print_stacks(t_stack *a, t_stack *b);
void	ft_putstr_fd(int fd, char *str);

void	exit_with_message(int exitcode, char *message);
int		ft_strlen(char *str);
void	*malloc_check(void *data);
bool	ft_isnumber(char *str);
int		ft_basic_itoa(char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

void	add_number_to_stack(t_stack *stack, int nb);
void	add_new_number_to_stack(t_stack *stack, int nb);
void	stack_init(t_stack *a, t_stack *b, int ac, char **av);

void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
