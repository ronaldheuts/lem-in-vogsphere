/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newroom.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:32:11 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 17:48:30 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*newroom(t_data *lemin)
{
	t_room	*new;
	int		i;

	i = 0;
	new = (t_room *)malloc(sizeof(t_room));
	if (!new)
		return (NULL);
	new->name = getroomname(lemin->walker->line, &i);
	if (!new->name)
		return (NULL);
	new->v = 0;
	new->level = -1;
	new->p_id = -1;
	new->a_id = 0;
	new->xy = getcoordinates(lemin->walker->line, &i);
	if (!new->xy)
		return (NULL);
	new->hashname = hash(new->name, lemin->map->n_rooms);
	new->hashxy = hash(new->xy, lemin->map->n_rooms);
	new->link = NULL;
	new->nextname = NULL;
	new->nextxy = NULL;
	return (new);
}
