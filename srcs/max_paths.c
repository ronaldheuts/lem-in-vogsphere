/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_paths.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 13:36:28 by anonymous     #+#    #+#                 */
/*   Updated: 2020/06/26 13:36:28 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		ft_min(int x, int y)
{
	if (x > y)
		return (y);
	return (x);
}

int		max_paths(t_room *start, t_room *end)
{
	int		i;
	int		j;
	t_link	*temp;

	i = 0;
	j = 0;
	temp = start->link;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	temp = end->link;
	while (temp)
	{
		j++;
		temp = temp->next;
	}
	return (ft_min(i, j));
}
