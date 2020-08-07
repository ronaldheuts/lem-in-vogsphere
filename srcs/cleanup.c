/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cleanup.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 15:06:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/29 16:39:24 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		reset_room(t_room *room)
{
	t_link	*link;

	link = room->link;
	while (link)
	{
		link->room->level = -1;
		link = link->next;
	}
}

void		clean_room(t_room *room)
{
	t_link	*link;

	link = room->link;
	while (link)
	{
		if (link->room->level == -1)
			remove_link(room, link->room);
		link = link->next;
	}
}

void		clean_map(t_data *lemin)
{
	create_levels(lemin->end, lemin->start, lemin);
	clean_room(lemin->start);
	reset_room(lemin->end);
	create_levels(lemin->start, lemin->end, lemin);
	clean_room(lemin->end);
}
