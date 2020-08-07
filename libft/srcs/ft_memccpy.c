/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 15:27:13 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:11:17 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ucdst;
	unsigned char	*ucsrc;
	unsigned char	ucc;
	size_t			i;

	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	ucc = (unsigned char)c;
	i = 0;
	while (n > i)
	{
		ucdst[i] = ucsrc[i];
		if (ucsrc[i] == ucc)
		{
			ucdst[i] = ucsrc[i];
			i++;
			return (dst + i);
		}
		i++;
	}
	return (NULL);
}
