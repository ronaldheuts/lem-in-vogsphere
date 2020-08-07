/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newcoordinatestable.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:42 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/01 13:39:07 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**newcoordinatestable(int size)
{
	int		i;
	char	**new;

	i = 0;
	if (!size)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	while (i <= size)
	{
		new[i] = NULL;
		i++;
	}
	return (new);
}
