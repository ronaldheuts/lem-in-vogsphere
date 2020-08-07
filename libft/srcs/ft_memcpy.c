/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 14:25:03 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:11:30 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	cdst = (char *)dst;
	csrc = (char *)src;
	i = 0;
	while (n > i)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
