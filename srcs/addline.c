/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   addline.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:28:38 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:54:01 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	addhead(t_line **head, t_line *new)
{
	new->next = *head;
	*head = new;
}

void	addtail(t_line **tail, t_line *new)
{
	(*tail)->next = new;
	*tail = new;
}
