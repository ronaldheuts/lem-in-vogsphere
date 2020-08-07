/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstback.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 15:39:46 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:10:46 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_lstback(t_list **lst, t_list *new)
{
	while ((*lst)->next != NULL)
	{
		(*lst) = (*lst)->next;
	}
	if ((*lst)->next == NULL)
	{
		(*lst)->next = new;
		new->next = NULL;
	}
}
