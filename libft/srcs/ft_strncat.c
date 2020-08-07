/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:15:43 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:13:27 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
	{
		while (s2[j] != '\0' && j < n)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	}
	s1[i] = '\0';
	return (s1);
}
