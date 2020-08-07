/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:27:47 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:12:33 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_strclr(char *s)
{
	size_t	len;
	size_t	i;

	if (s != NULL)
	{
		len = ft_strlen(s);
		i = 0;
		while (len > i)
		{
			s[i] = '\0';
			i++;
		}
	}
}
