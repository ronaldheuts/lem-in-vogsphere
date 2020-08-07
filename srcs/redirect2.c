/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect2.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:53:25 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/29 17:04:38 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		at_end(t_room *room, t_data *lemin)
{
	t_link	*link;

	link = room->link;
	while (link)
	{
		if (link->room == lemin->end)
			return (1);
		link = link->next;
	}
	return (0);
}

int		valid_end_link(t_room *room, t_data *lemin)
{
	if (room->v >= lemin->iter)
		return (0);
	if (room->p_id >= lemin->alter)
		return (0);
	return (1);
}

t_room	*end_link(t_room *room, t_data *lemin)
{
	t_link	*link;
	t_room	*ret;

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
				if (valid_end_link(link->room, lemin))
					ret = link->room;
			}
			else if (valid_end_link(link->room, lemin) &&
				link->room->level < ret->level)
				ret = link->room;
		}
		link = link->next;
	}
	if (ret)
		ret->v = lemin->iter;
	return (ret);
}

int		compare_block(t_room *old, t_room *new, t_room *room)
{
	if (new->p_id != room->p_id)
		return (0);
	if (old && new->level < old->level)
		return (0);
	return (1);
}

int		count_links(t_room *room, int iter)
{
	int		c;
	t_link	*link;

	link = room->link;
	c = 0;
	while (link)
	{
		if (link->on == 1 && iter > -1000)
		{
			c++;
		}
		link = link->next;
	}
	return (c);
}
