/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getroom.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:27:58 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 18:05:56 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*getroom(char *s, t_data *lemin)
{
	t_room	*walker;

	if (!s || !lemin->hashtable)
		return (NULL);
	walker = lemin->hashtable[hash(s, lemin->map->n_rooms)];
	while (walker)
	{
		if (!ft_strcmp(walker->name, s))
			return (walker);
		walker = walker->nextname;
	}
	return (NULL);
}
