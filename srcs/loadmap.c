/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loadmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:23 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 16:00:15 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		loadmap(t_map *input)
{
	int		key;
	char	*s;
	t_line	*new;

	key = get_next_line(STDIN_FILENO, &s);
	if (!key)
		return (0);
	while (key)
	{
		if (key < 0)
			return (0);
		new = newline(s);
		if (!input->head && !input->tail)
		{
			addhead(&input->head, new);
			input->tail = input->head;
		}
		else
			addtail(&input->tail, new);
		key = get_next_line(STDIN_FILENO, &s);
	}
	return (1);
}
