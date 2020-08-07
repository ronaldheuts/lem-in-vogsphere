/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 14:01:03 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:16:11 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char		**fillwords(const char *s, char c, char **new)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
		{
			new[n] = ft_strndup(s + i, j);
			n++;
		}
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (new);
}

static size_t	getwords(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
			n++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (n);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t	w;
	char	**new;

	if (!s)
		return (NULL);
	w = getwords(s, c);
	new = (char **)malloc(sizeof(char *) * (w + 1));
	if (!new)
		return (NULL);
	new[w] = NULL;
	fillwords(s, c, new);
	return (new);
}
