/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freelinks.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:17 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/30 15:57:04 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	freelinks(t_link **head)
{
	t_link	*walker;
	t_link	*next;

	walker = *head;
	while (walker)
	{
		next = walker->next;
		ft_memdel((void **)&walker);
		walker = next;
	}
}
