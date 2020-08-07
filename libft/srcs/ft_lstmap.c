/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 12:21:59 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:11:05 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;
	t_list	*tmp;

	head = f(lst);
	if (head == NULL)
		return (NULL);
	tmp = head;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (new == NULL)
			return (NULL);
		ft_lstback(&tmp, new);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (head);
}
