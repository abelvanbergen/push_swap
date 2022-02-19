/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 10:27:22 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/02/18 12:25:49 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "push_swap.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	exit_with_message(int exitcode, char *message)
{
	ft_putstr_fd(2, "error:\n");
	ft_putstr_fd(2, message);
	ft_putstr_fd(2, "\n");
	exit(exitcode);
}

void	*malloc_check(void *data)
{
	if (data == NULL)
		exit_with_message(1, "malloc failed");
	return (data);
}

static bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (ft_strlen(str + i) == 0)
		return false;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
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
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * neg);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	if (dst < src)
	{
		while (i < (int)len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		i = (int)len - 1;
		while (i >= 0)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i--;
		}
	}
	return (dst);
}