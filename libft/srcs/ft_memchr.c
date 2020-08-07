/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:45:42 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:11:20 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ucs;
	unsigned char	ucc;
	unsigned int	i;

	ucs = (unsigned char *)s;
	ucc = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		if (ucs[i] == ucc)
			return ((unsigned char *)s + i);
		n--;
		i++;
	}
	return (NULL);
}
