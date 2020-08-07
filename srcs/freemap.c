/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freemap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:25 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:57:17 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	freelines(t_line **head)
{
	t_line	*walker;
	t_line	*next;

	if (!*head)
		return ;
	walker = *head;
	while (walker)
	{
		next = walker->next;
		ft_memdel((void **)&walker->line);
		ft_memdel((void **)&walker);
		walker = next;
	}
}

void		freemap(t_map *p)
{
	if (!p)
		return ;
	freelines(&p->head);
	ft_memdel((void **)&p);
}
