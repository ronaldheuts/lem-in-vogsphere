/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isroom.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 17:54:02 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 17:09:46 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	Returns '1' if a lem-in room is valid, else '0'.
*/

int		isroom(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (!isroomname(s, &i))
		return (0);
	if (!iscoordinate(s, &i))
		return (0);
	if (!iscoordinate(s, &i))
		return (0);
	if (!ischaracter(s[i], 0))
		return (0);
	return (1);
}
