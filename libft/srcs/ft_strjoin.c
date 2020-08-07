/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:49:03 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:13:05 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_fill_arr(char const *s1, char const *s2, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*tmp;

	i = 0;
	j = 0;
	tmp = ft_strnew(len);
	if (tmp == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		tmp[i + j] = s2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*tmp;

	tmp = NULL;
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		tmp = ft_fill_arr(s1, s2, len);
	}
	return (tmp);
}
