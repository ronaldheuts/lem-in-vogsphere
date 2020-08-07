/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isduplicateroom.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:30:31 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 17:52:43 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		isduplicateroom(t_room *head, char *new)
{
	t_room	*walker;

	walker = head;
	while (walker)
	{
		if (!ft_strcmp(walker->name, new))
			return (1);
		walker = walker->nextname;
	}
	return (0);
}

int		isduplicatexy(t_room *head, char *new)
{
	t_room	*walker;

	walker = head;
	while (walker)
	{
		if (!ft_strcmp(walker->xy, new))
			return (1);
		walker = walker->nextxy;
	}
	return (0);
}
