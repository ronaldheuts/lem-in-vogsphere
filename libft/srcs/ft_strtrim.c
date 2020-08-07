/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:57:47 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:15:11 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int		str_start(char const *s)
{
	int		i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
		i++;
	return (i);
}

static int		str_end(char const *s)
{
	int		i;

	i = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' ||
			s[i] == '\t' || s[i] == '\0') && (i > 0))
		i--;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		k;
	char	*tmp;

	k = 0;
	tmp = NULL;
	if (s != NULL)
	{
		start = str_start(s);
		end = str_end(s);
		if ((end - start) < 0)
			tmp = (char *)malloc(sizeof(char) * 1);
		else
			tmp = (char *)malloc(sizeof(char) * (end - start) + 2);
		if (tmp == NULL)
			return (NULL);
		while ((start + k) <= end)
		{
			tmp[k] = s[start + k];
			k++;
		}
		tmp[k] = '\0';
	}
	return (tmp);
}
