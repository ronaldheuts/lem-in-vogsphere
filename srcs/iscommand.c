/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iscommand.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:30:39 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:03:27 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	Returns '1' if the string is a lem-in command, else '0'.
*/

int		iscommand(t_data *lemin)
{
	if (!lemin->walker || !lemin->walker->line)
		return (0);
	else if (!ft_strcmp("##start", lemin->walker->line) && !lemin->roomtype &&
	!lemin->start)
		lemin->roomtype = ROOM_START;
	else if (!ft_strcmp("##end", lemin->walker->line) && !lemin->roomtype &&
	!lemin->end)
		lemin->roomtype = ROOM_END;
	else
		return (0);
	return (1);
}
