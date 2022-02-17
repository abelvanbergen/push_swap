/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: avan-ber <avan-ber@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 19:51:51 by avan-ber      #+#    #+#                 */
/*   Updated: 2022/02/17 20:08:49 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack
{
	int				*stack;
	unsigned int	size;
	unsigned int	capacity;
}					t_stack;

#endif
