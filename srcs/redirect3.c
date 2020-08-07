/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect3.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:57:21 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/29 17:21:56 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		compare_rooms(t_room *old, t_room *new, t_data *lemin)
{
	if (new == lemin->end)
		return (0);
	if (at_end(new, lemin))
		return (0);
	if (new->v >= lemin->iter)
		return (0);
	if (new->p_id >= lemin->alter)
		return (1);
	if (old && new->level >= old->level)
		return (0);
	return (1);
}

t_link			*best_rlink(t_room *room, t_data *lemin)
{
	t_link	*link;
	t_link	*ret;

	link = room->link;
	ret = NULL;
	while (link)
	{
		if (link->on == 1)
		{
			if (link->room == lemin->start)
				link = link->next;
			else if (!ret)
			{
				if (compare_rooms(NULL, link->room, lemin))
					ret = link;
			}
			else if (compare_rooms(ret->room, link->room, lemin))
				ret = link;
		}
		link = link->next;
	}
	if (!(ret) || ret->room->v >= lemin->iter)
		return (NULL);
	ret->room->v = lemin->iter;
	return (ret);
}
