/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addtable.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:28:58 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:24:04 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** In case of a collision (multiple entries on the same index of
** the hashtable), the new entry is added to the front of the linked list.
*/

static int	addcoordinates(t_data *lemin, t_room *new)
{
	if (lemin->xytable[new->hashxy])
	{
		if (isduplicatexy(lemin->xytable[new->hashxy], new->xy))
		{
			ft_printf("[Error] Duplicate coordinates in map: %s\n", new->xy);
			ft_memdel((void **)&new->xy);
			ft_memdel((void **)&new->name);
			ft_memdel((void **)&new);
			return (0);
		}
		else
			addlistxybucket(&lemin->xytable[new->hashxy], new);
	}
	else
		addlistxybucket(&lemin->xytable[new->hashxy], new);
	return (1);
}

static int	addroom(t_data *lemin, t_room *new)
{
	if (lemin->hashtable[new->hashname])
	{
		if (isduplicateroom(lemin->hashtable[new->hashname], new->name))
		{
			ft_printf("[Error] Duplicate room name in map: %s\n", new->name);
			ft_memdel((void **)&new->xy);
			ft_memdel((void **)&new->name);
			ft_memdel((void **)&new);
			return (0);
		}
		else
			addlistnamebucket(&lemin->hashtable[new->hashname], new);
	}
	else
		addlistnamebucket(&lemin->hashtable[new->hashname], new);
	return (1);
}

int			addtable(t_data *lemin)
{
	t_room	*new;

	new = newroom(lemin);
	if (!new)
		return (0);
	if (!addcoordinates(lemin, new))
		return (0);
	if (!addroom(lemin, new))
		return (0);
	if (lemin->roomtype == ROOM_START && !lemin->start)
		lemin->start = new;
	else if (lemin->roomtype == ROOM_END && !lemin->end)
		lemin->end = new;
	lemin->roomtype = ROOM_DEFAULT;
	return (1);
}
