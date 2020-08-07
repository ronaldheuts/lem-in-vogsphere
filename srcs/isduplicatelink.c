/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isduplicatelink.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:30:27 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 14:52:58 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		isduplicatelink(t_room *head, char *new)
{
	t_link	*walker;

	walker = head->link;
	while (walker)
	{
		if (!ft_strcmp(walker->room->name, new))
			return (1);
		walker = walker->next;
	}
	return (0);
}
