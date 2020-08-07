/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newmap.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:32:04 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/01 13:40:22 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_map	*newmap(void)
{
	t_map	*new;

	new = (t_map *)malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->head = NULL;
	new->tail = NULL;
	new->n_rooms = 0;
	return (new);
}
