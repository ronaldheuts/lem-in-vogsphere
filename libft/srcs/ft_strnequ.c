/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnequ.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 19:24:58 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:14:29 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		while ((s1[i] != '\0') && (n > 0) && (s1[i] == s2[i]))
		{
			i++;
			n--;
		}
		if ((s1[i] == '\0' && s2[i] == '\0') || (n == 0))
			return (1);
	}
	return (0);
}
