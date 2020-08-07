/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   islinkname.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:30:40 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 17:22:37 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		islinkname(char *s)
{
	if (!s)
		return (0);
	if (*s == 'L' || *s == '#' || *s == '-' || !ft_isgraph(*s))
		return (0);
	while (*s && ft_isgraph(*s) && *s != '-')
		s++;
	if (*s != '-')
		return (0);
	s++;
	if (!ft_isgraph(*s))
		return (0);
	while (*s && *s != '-' && ft_isgraph(*s))
		s++;
	if (*s)
		return (0);
	return (1);
}
