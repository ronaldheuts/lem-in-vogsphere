/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:30:15 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:15:07 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*tmp;

	j = 0;
	tmp = NULL;
	if (s != NULL)
	{
		tmp = (char *)malloc(sizeof(char) * (len + 1));
		if (tmp == NULL)
			return (NULL);
		while (s[start] != '\0' && len > j)
		{
			tmp[j] = s[start + j];
			j++;
		}
		tmp[j] = '\0';
	}
	return (tmp);
}
