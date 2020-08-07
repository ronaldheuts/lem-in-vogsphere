/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 10:38:22 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:10:35 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa(int n, char *buffer, int radix)
{
	char	*base;
	size_t	i;

	base = "0123456789abcdef";
	i = ft_nlen(n, radix);
	if (n < 0 && radix == 10)
	{
		buffer[0] = '-';
		n *= -1;
	}
	while (n && i)
	{
		i--;
		buffer[i] = base[n % radix];
		n /= radix;
	}
	return (buffer);
}
