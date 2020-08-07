/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addlist.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:28:50 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:54:12 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	addlistnamebucket(t_room **head, t_room *new)
{
	if (!new)
		return ;
	new->nextname = *head;
	*head = new;
}

void	addlistxybucket(t_room **head, t_room *new)
{
	if (!new)
		return ;
	new->nextxy = *head;
	*head = new;
}
