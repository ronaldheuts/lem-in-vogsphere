/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newlink.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:58 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 18:01:54 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_link	*newlink(char *s, t_data *lemin)
{
	t_link	*new;

	new = (t_link *)malloc(sizeof(t_link));
	if (!new)
		return (NULL);
	new->room = getroom(s, lemin);
	if (!new->room)
	{
		ft_memdel((void **)&new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
