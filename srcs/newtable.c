/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newtable.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:32:15 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/01 13:41:58 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	**newtable(unsigned int size)
{
	unsigned int	i;
	t_room			**new;

	i = 0;
	if (!size)
		return (NULL);
	new = (t_room **)malloc(sizeof(t_room *) * (size + 1));
	if (!new)
		return (NULL);
	while (i <= size)
	{
		new[i] = NULL;
		i++;
	}
	return (new);
}
