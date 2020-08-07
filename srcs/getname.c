/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getname.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 18:19:16 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:58:19 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Room names can not start with the characters 'L' or '#' and can not
** contain a '-', as this character is reserved as seperator character
** for links.
*/

char	*getroomname(char *s, int *i)
{
	char	*name;

	if (!s)
		return (0);
	while (s[*i] && s[*i] != ' ')
		(*i)++;
	name = ft_strndup(s, *i);
	if (!name)
		return (NULL);
	return (name);
}
