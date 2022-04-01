/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 10:27:22 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/03/28 20:08:36 by avan-ber      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "../../includes/push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i_len;

	i = 0;
	i_len = 0;
	if (src == 0)
		return (0);
	i_len = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i + 1 < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i_len);
}

char	*ft_strdup(const char *str)
{
	const int	len = ft_strlen(str);
	char		*new;

	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, str, len + 1);
	return (new);
}

char	*ft_strjoin_and_free_s1(char *s1, char *s2)
{
	const int	len_s1 = ft_strlen(s1);
	const int	len_s2 = ft_strlen(s2);
	char		*str;

	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, len_s1 + 1);
	ft_strlcpy(str + len_s1, s2, len_s2 + 1);
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*str;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (start + len <= s_len)
		str = (char *)malloc(len + 1);
	else
		str = (char *)malloc(s_len - start + 1);
	if (str == 0)
		return (0);
	while (i < len && s[start + i] != '\0')
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	exit_with_message(int exitcode, char *message)
{
	(void)message;
	ft_putstr_fd(2, "Error\n");
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

bool	ft_basic_atoi(char *str, int *res)
{
	int		i;
	int		neg;
	long	nb;

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
		if (nb > (long)INT32_MAX + 1)
			return (false);
		i++;
	}
	nb *= neg;
	*res = nb;
	if (*res != nb)
		return (false);
	return (true);
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