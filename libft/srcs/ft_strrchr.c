/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 14:04:58 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:14:53 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char)c;
	while (s[i] != '\0')
		i++;
	while (i > 0 && s[i] != cc)
		i--;
	if (i == 0 && s[i] != cc)
		return (NULL);
	return ((char *)s + i);
}
