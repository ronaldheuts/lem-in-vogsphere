/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   algorithm.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/29 12:01:10 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/18 12:07:44 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		remove_link(t_room *room1, t_room *room2)
{
	t_link	*link;

	link = room1->link;
	while (link)
	{
		if (link->room == room2)
		{
			link->on = 0;
			break ;
		}
		link = link->next;
	}
	link = room2->link;
	while (link)
	{
		if (link->room == room1)
		{
			link->on = 0;
			break ;
		}
		link = link->next;
	}
}

int			start_end(t_data *lemin)
{
	t_link	*link;

	link = lemin->start->link;
	while (link)
	{
		if (link->room == lemin->end)
			return (1);
		link = link->next;
	}
	return (0);
}

int			algorithm(t_data *lemin)
{
	lemin->max = max_paths(lemin->start, lemin->end);
	if (lemin->max < 1)
		return (-1);
	if (start_end(lemin))
		remove_link(lemin->start, lemin->end);
	while (1)
	{
		if (create_levels(lemin->end, lemin->start, lemin) == -1)
			return (-1);
		lemin->paths = compare(lemin);
		lemin->iter++;
		if (!redirect(lemin))
		{
			return (1);
		}
	}
	return (-1);
}
