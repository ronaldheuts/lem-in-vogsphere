/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newlemin.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:49 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/01 14:36:27 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	countrooms(t_map *input)
{
	t_line	*walker;

	walker = input->head;
	while (walker)
	{
		if (isroom(walker->line))
			input->n_rooms++;
		walker = walker->next;
	}
}

t_data	*newlemin(t_map *input)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (!new)
		return (NULL);
	new->map = input;
	new->hashtable = newtable(input->n_rooms);
	new->xytable = newtable(input->n_rooms);
	new->start = NULL;
	new->end = NULL;
	new->rooms = NULL;
	new->paths = NULL;
	new->alter = 0;
	new->score = 0;
	new->walker = input->head;
	new->ants = 0;
	new->roomtype = 0;
	new->iter = 1;
	return (new);
}
