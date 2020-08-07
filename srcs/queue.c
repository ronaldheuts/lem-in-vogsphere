/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   queue.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/29 21:36:57 by anonymous     #+#    #+#                 */
/*   Updated: 2020/07/29 16:33:15 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		remove_from_queue(t_queue *queue)
{
	t_link *temp;

	if (!queue)
		return (-1);
	if (!queue->head)
		return (-1);
	temp = queue->head->next;
	free(queue->head);
	queue->head = temp;
	queue->len--;
	return (0);
}

int		add_item(t_queue *queue, t_link *link)
{
	t_link	*item;

	item = (t_link*)malloc(sizeof(t_link));
	item->room = link->room;
	if (!item)
		return (-1);
	if (queue->len == 0)
	{
		queue->head = item;
		queue->tail = item;
		queue->len++;
	}
	else
	{
		queue->tail->next = item;
		queue->tail = item;
		queue->len++;
	}
	return (0);
}

int		add_to_queue(t_room *room, t_queue *queue, t_data *lemin, int type)
{
	t_link	*temp;

	if (!room || !queue)
		return (-1);
	temp = room->link;
	while (temp)
	{
		if (temp->room->v < lemin->iter && temp->on == 1)
		{
			if (type == 0 || (type == 1 && temp->room->p_id < lemin->alter))
			{
				add_item(queue, temp);
				temp->room->level = room->level + 1;
				temp->room->v = lemin->iter;
			}
		}
		temp = temp->next;
	}
	return (0);
}

void	initialize_queue(t_queue *queue)
{
	queue->head = NULL;
	queue->tail = NULL;
	queue->len = 0;
}
