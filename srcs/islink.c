/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   islink.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 18:17:27 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:58:50 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**  Return 1 if a valid link is added between two known rooms, else return 0.
*/

int		islink(t_data *lemin)
{
	if (!lemin->walker || !lemin->walker->line)
		return (0);
	if (!islinkname(lemin->walker->line))
		return (0);
	return (1);
}
