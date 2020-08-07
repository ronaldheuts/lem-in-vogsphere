/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getcoordinates.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:51 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:58:02 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*getcoordinates(char *s, int *i)
{
	char	*coordinates;

	if (!s)
		return (0);
	if (s[*i] == ' ')
		(*i)++;
	coordinates = ft_strdup(s + *i);
	return (coordinates);
}
