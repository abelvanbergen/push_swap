/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 19:51:51 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/21 17:36:24 by avan-ber      ########   odam.nl         */
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

typedef void	(*t_rotate)(t_stack*);

typedef struct s_numberinfo
{
	unsigned int	idx;
	int				nb;
	t_rotate		r;
	char			str[5];
}					t_numberinfo;

void	print_stacks(t_stack *a, t_stack *b);
void	ft_putstr_fd(int fd, char *str);

int		ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *str);
char	*ft_strjoin_and_free_s1(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	exit_with_message(int exitcode, char *message);
void	*malloc_check(void *data);
bool	ft_isnumber(char *str);
int		ft_basic_itoa(char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);

void	stack_init_push_swap(t_stack *a, t_stack *b, int ac, char **av);
void	stack_init_checker(t_stack *a, t_stack *b, int ac, char **av);

void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	double_swap(t_stack *a, t_stack *b);
void	double_rotate(t_stack *a, t_stack *b);
void	double_reverse_rotate(t_stack *a, t_stack *b);

#endif
