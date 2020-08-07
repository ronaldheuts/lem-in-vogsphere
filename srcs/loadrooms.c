/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loadrooms.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:29 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 16:59:19 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		loadrooms(t_data *lemin)
{
	while (lemin->walker)
	{
		if (iscommand(lemin))
			lemin->walker = lemin->walker->next;
		else if (iscomment(lemin->walker->line))
			lemin->walker = lemin->walker->next;
		else if (isroom(lemin->walker->line))
		{
			if (!addtable(lemin))
				return (0);
			lemin->walker = lemin->walker->next;
		}
		else if (islink(lemin))
			break ;
		else
		{
			ft_printf("[Error] Invalid command or room: %s\n",
			lemin->walker->line);
			return (0);
		}
	}
	return (1);
}
