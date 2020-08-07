/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iscomment.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:27:51 by rheuts        #+#    #+#                 */
/*   Updated: 2020/03/12 16:27:52 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		iscomment(const char *s)
{
	if (!s)
		return (0);
	if (!ft_strcmp("##start", s) || !ft_strcmp("##end", s))
		return (0);
	if (*s == '#')
		return (1);
	return (0);
}
