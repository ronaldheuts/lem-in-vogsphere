/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freelist.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:21 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:57:11 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	freelist(t_room **head)
{
	t_room	*walker;
	t_room	*next;

	walker = *head;
	while (walker)
	{
		next = walker->nextname;
		if (walker->link)
			freelinks(&walker->link);
		ft_memdel((void **)&walker->name);
		ft_memdel((void **)&walker->xy);
		ft_memdel((void **)&walker);
		walker = next;
	}
}
