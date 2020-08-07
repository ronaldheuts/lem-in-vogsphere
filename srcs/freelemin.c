/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freelemin.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:07 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:56:55 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	freerooms(t_data *lemin)
{
	if (!lemin || !lemin->rooms)
		return ;
	ft_memdel((void **)&lemin->rooms[0]);
	ft_memdel((void **)&lemin->rooms[1]);
	ft_memdel((void **)&lemin->rooms);
}

void	freelemin(t_data **lemin)
{
	if (!lemin)
		return ;
	freetable((*lemin)->hashtable, (*lemin)->map->n_rooms);
	freemap((*lemin)->map);
	freerooms(*lemin);
	ft_memdel((void **)&(*lemin)->xytable);
	ft_memdel((void **)lemin);
}
