/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: abelfranciscusvanbergen <abelfranciscus      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/18 13:18:25 by abelfrancis   #+#    #+#                 */
/*   Updated: 2022/02/18 13:32:40 by abelfrancis   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define BUFFER_SIZE 42

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	const int	len_s1 = ft_strlen(s1);
	const int	len_s2 = ft_strlen(s2);
	char		*str;


}

int	main(void)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;
	char	line;

	bytes_read = 1;
	buf[BUFFER_SIZE] = '\0';
	while (bytes_read > 0)
	{
		bytes_read = read(0, buf, BUFFER_SIZE);

	}
}
