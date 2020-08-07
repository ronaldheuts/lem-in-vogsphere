/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addlink.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:28:43 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 18:36:21 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	addlink(t_link **head, t_link *new)
{
	new->next = *head;
	*head = new;
	new->on = 1;
}

static void	freetemplinks(t_link *a, t_link *b)
{
	ft_memdel((void **)&a);
	ft_memdel((void **)&b);
}

static int	isknownroom(t_data *lemin)
{
	if (!isduplicateroom(lemin->hashtable[hash(lemin->rooms[0],
	lemin->map->n_rooms)], lemin->rooms[0]))
	{
		freerooms(lemin);
		return (0);
	}
	if (!isduplicateroom(lemin->hashtable[hash(lemin->rooms[1],
	lemin->map->n_rooms)], lemin->rooms[1]))
	{
		freerooms(lemin);
		return (0);
	}
	return (1);
}

int			addlistlink(t_data *lemin)
{
	t_link	*a;
	t_link	*b;

	lemin->rooms = ft_strsplit(lemin->walker->line, '-');
	if (!lemin->rooms || !ft_strcmp(lemin->rooms[0], lemin->rooms[1]))
		return (0);
	if (!isknownroom(lemin))
		return (0);
	a = newlink(lemin->rooms[0], lemin);
	b = newlink(lemin->rooms[1], lemin);
	if (!a || !b)
	{
		freetemplinks(a, b);
		return (0);
	}
	if (isduplicatelink(getroom(lemin->rooms[0], lemin), lemin->rooms[1]))
	{
		freetemplinks(a, b);
		return (0);
	}
	addlink(&getroom(lemin->rooms[0], lemin)->link, b);
	addlink(&getroom(lemin->rooms[1], lemin)->link, a);
	freerooms(lemin);
	return (1);
}
