/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/22 20:27:04 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/07 16:35:31 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int			compare_rooms(t_room *old, t_room *new, int iter, int alter)
{
	if (new->p_id >= alter)
		return (0);
	if (new->v >= iter)
		return (0);
	if (old && new->level >= old->level)
		return (0);
	return (1);
}

static t_link		*best_link(t_room *room, t_data *lemin)
{
	t_link	*link;
	t_link	*ret;

	link = room->link;
	ret = NULL;
	while (link)
	{
		if (room != lemin->start && link->room == lemin->end)
			return (link);
		else if (!ret)
		{
			if (link->on &&
				compare_rooms(NULL, link->room, lemin->iter, lemin->alter))
				ret = link;
		}
		else if (link && link->on == 1 &&
			compare_rooms(ret->room, link->room, lemin->iter, lemin->alter) &&
			link->room != lemin->start)
			ret = link;
		link = link->next;
	}
	if (!(ret) || ret->room->v >= lemin->iter)
		return (NULL);
	ret->room->v = lemin->iter;
	return (ret);
}

static t_pnode		*find_path(t_room *room, t_data *lemin, int p_id)
{
	t_pnode	*node;
	t_pnode *next;
	t_link	*link;

	next = NULL;
	if (room == lemin->end)
	{
		node = new_node(room, NULL);
		return (node);
	}
	link = best_link(room, lemin);
	while (link)
	{
		next = find_path(link->room, lemin, p_id);
		if (next)
		{
			node = new_node(room, next);
			node->next->prev = node;
			room->p_id = lemin->alter + p_id;
			return (node);
		}
		link = best_link(room, lemin);
	}
	room->v = lemin->iter;
	return (NULL);
}

t_path				*set_path_data(t_path *path, int *p_id)
{
	path->length = get_path_data(path->path);
	path->next = new_path();
	*p_id += 1;
	return (path->next);
}

t_path				*get_paths(t_data *lemin, int p_id)
{
	t_path	*path;
	t_path	*head;
	t_link	*link;

	path = new_path();
	head = path;
	link = best_link(lemin->start, lemin);
	if (start_end(lemin))
	{
		path->path = start_end_path(lemin);
		path = set_path_data(path, &p_id);
	}
	while (link)
	{
		path->path = find_path(link->room, lemin, p_id);
		if (path->path)
		{
			path = set_path_data(path, &p_id);
			create_levels(lemin->end, lemin->start, lemin);
		}
		link = best_link(lemin->start, lemin);
	}
	path->next = NULL;
	cut_tail(head);
	return (head);
}
