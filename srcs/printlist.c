/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printlist.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:32:19 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/01 13:42:18 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	printlist(t_room *head)
{
	t_room	*walker;

	walker = head;
	while (walker)
	{
		ft_printf("\tname: %s\n", walker->name);
		walker = walker->nextname;
	}
	walker = head;
	while (walker)
	{
		ft_printf("\tname: %s\n", walker->name);
		walker = walker->nextxy;
	}
}

void	printlink(t_link *head)
{
	t_link	*walker;

	walker = head;
	while (walker)
	{
		ft_printf("%s->", walker->room->name);
		walker = walker->next;
	}
	ft_printf("NULL\n");
}
