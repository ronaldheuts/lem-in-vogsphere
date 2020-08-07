/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nlen.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/10 17:53:16 by rheuts        #+#    #+#                 */
/*   Updated: 2019/06/10 17:53:17 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_nlen(int64_t n, int radix)
{
	size_t	len;

	len = 0;
	if (n < 0 && radix == 10)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= radix;
		len++;
	}
	return (len);
}
