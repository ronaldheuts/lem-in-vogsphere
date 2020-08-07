/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isroomname.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 17:42:11 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 14:40:56 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**	Returns '1' if the roomname is valid, else '0'.
**	Room name can not start with a 'L' or '#' and can not contain a '-'.
*/

int		isroomname(char *s, int *i)
{
	if (!s)
		return (0);
	if (s[*i] == 'L' || s[*i] == '#')
		return (0);
	while (ft_isgraph(s[*i]) && s[*i] != '-')
		(*i)++;
	return (1);
}
