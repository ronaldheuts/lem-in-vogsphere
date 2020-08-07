/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 11:43:34 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:13:10 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	result;
	size_t	j;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = 0;
	if (dst_len >= size)
		return (src_len + size);
	while (src[j] != '\0' && size > dst_len + 1)
	{
		dst[dst_len + j] = src[j];
		j++;
		size--;
	}
	dst[dst_len + j] = '\0';
	result = src_len + dst_len;
	return (result);
}
