/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/16 15:24:35 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:13:33 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	unsigned int	i;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((ucs1[i] != '\0') && (n > 0))
	{
		n--;
		if (ucs1[i] != ucs2[i] || n == 0)
			return (ucs1[i] - ucs2[i]);
		i++;
	}
	return (ucs1[i] - ucs2[i]);
}
