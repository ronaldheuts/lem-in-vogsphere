/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loadlinks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:15 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 18:38:29 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		loadlinks(t_data *lemin)
{
	while (lemin->walker)
	{
		if (iscomment(lemin->walker->line))
		{
			lemin->walker = lemin->walker->next;
			continue ;
		}
		else if (islink(lemin))
		{
			if (!addlistlink(lemin))
				return (0);
		}
		else
			return (0);
		lemin->walker = lemin->walker->next;
	}
	if (lemin->walker)
		return (0);
	return (1);
}
