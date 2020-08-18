/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 19:21:43 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/18 12:09:26 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		create_levels(t_room *start, t_room *end, t_data *lemin)
{
	t_queue		*q;
	int			type;

	type = 0;
	if (start == lemin->end)
		type = 1;
	q = (t_queue*)malloc(sizeof(t_queue));
	if (!q || !end)
		exit(0);
	lemin->iter++;
	start->level = 0;
	start->v = lemin->iter;
	initialize_queue(q);
	add_to_queue(start, q, lemin, type);
	while (q->len > 0)
	{
		if (q->head->room != end)
			add_to_queue(q->head->room, q, lemin, type);
		remove_from_queue(q);
	}
	free(q);
	lemin->iter++;
	return (0);
}
