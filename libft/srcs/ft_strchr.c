/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:40:17 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:12:29 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char)c;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == cc)
				return ((char *)s + i);
			i++;
		}
		if (s[i] == '\0' && cc == '\0')
			return ((char *)s + i);
	}
	return (NULL);
}
