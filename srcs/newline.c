/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newline.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:54 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 16:44:25 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_line	*newline(char *s)
{
	t_line	*new;

	new = (t_line *)malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	new->line = s;
	new->next = NULL;
	return (new);
}
