/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 19:51:51 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/04/01 13:09:16 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_2int
{
	int	first;
	int	second;
}		t_2int;

typedef struct s_bucket_info
{
	int				*groupsize;
	unsigned int	groups;
	t_2int			*borders;
}				t_bucket_info;

typedef struct s_stack
{
	char			name;
	int				*stack;
	unsigned int	size;
	unsigned int	capacity;
}					t_stack;

typedef void	(*t_rotate)(t_stack*);

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
bool	ft_basic_atoi(char *str, int *res);
void	*ft_memmove(void *dst, const void *src, size_t len);

void	sort_2_numbers(t_stack *a);
void	sort_3_numbers(t_stack *a);
void	sort_4_numbers(t_stack *a, t_stack *b);
void	sort_5_numbers(t_stack *a, t_stack *b);

unsigned int	get_idx_nb(t_stack *stack, int nb);
int	get_max_nb(t_stack *stack);
bool	is_duplicate(t_stack *stack, int nb);

void	add_nb_to_stack(t_stack *stack, int nb);
void	add_nb_to_stack_on_idx(t_stack *stack, int nb, unsigned int idx);
void	add_new_nb_to_stack(t_stack *stack, int nb);
void	remove_nb_from_stack(t_stack *stack, unsigned int idx);
void	stack_cpy(t_stack *dest, t_stack *src);

void	stack_init_empty(t_stack *stack, unsigned int capacity);
void	stack_init_push_swap(t_stack *a, t_stack *b, int ac, char **av);
void	stack_init_checker(t_stack *a, t_stack *b, int ac, char **av);

void	swap(t_stack *stack);
void	push(t_stack *dest, t_stack *src);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

void	double_swap(t_stack *a, t_stack *b);
void	double_rotate(t_stack *a, t_stack *b);
void	double_reverse_rotate(t_stack *a, t_stack *b);
void	push_bottum(t_stack *dest, t_stack *srcs);

#endif
