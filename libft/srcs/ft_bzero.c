/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 15:43:28 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:09:39 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void			ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n > 0)
	{
		((unsigned char *)s)[i] = 0;
		i++;
		n--;
	}
}
