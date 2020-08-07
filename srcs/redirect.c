/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   redirect.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/23 13:45:03 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/29 17:19:01 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*get_block(t_room *room)
{
	t_link	*link;
	t_room	*ret;

	link = room->link;
	ret = NULL;
	while (!ret)
	{
		if (link->on && link->room->p_id == room->p_id)
			ret = link->room;
		link = link->next;
	}
	while (link)
	{
		if (link->on == 1 && compare_block(ret, link->room, room))
			ret = link->room;
		link = link->next;
	}
	return (ret);
}

int		select_cut(t_room *room, t_room *prev, t_data *lemin)
{
	t_link	*link;
	int		ret;

	link = room->link;
	ret = 0;
	room->v = lemin->iter;
	if (count_links(room, lemin->iter) > 2)
	{
		remove_link(room, prev);
		return (1);
	}
	if (room == lemin->start || room == lemin->end)
		return (0);
	while (link)
	{
		if (link->on == 1)
		{
			if (link->room->p_id == room->p_id && link->room->v < lemin->iter)
				ret = select_cut(link->room, room, lemin);
		}
		if (ret)
			return (1);
		link = link->next;
	}
	return (0);
}

int		find_blockage(t_room *room, t_data *lemin)
{
	t_link	*link;
	int		ret;

	link = room->link;
	ret = 0;
	while (link)
	{
		if (link->on == 1)
		{
			if (link->room->p_id == room->p_id)
				ret = select_cut(link->room, room, lemin);
		}
		if (ret)
			return (1);
		link = link->next;
	}
	return (ret);
}

int		find_block(t_room *room, t_data *lemin)
{
	t_link	*link;
	int		ret;

	if (!room)
		return (-1);
	if (room->p_id >= lemin->alter)
	{
		ret = find_blockage(room, lemin);
		return (ret);
	}
	link = best_rlink(room, lemin);
	while (link)
	{
		ret = find_block(link->room, lemin);
		if (ret == 1)
			return (1);
		link = best_rlink(room, lemin);
	}
	room->v = lemin->iter;
	return (0);
}

int		redirect(t_data *lemin)
{
	int		ret;

	ret = 0;
	create_levels(lemin->start, lemin->end, lemin);
	while (ret == 0)
		ret = find_block(end_link(lemin->end, lemin), lemin);
	lemin->alter += lemin->max;
	if (ret == 1)
		return (1);
	return (0);
}
