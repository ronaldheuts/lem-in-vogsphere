/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   score2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 16:58:17 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/08/03 17:01:10 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			next_queue_length(t_path *paths)
{
	t_path	*temp;
	int		t;

	temp = paths;
	t = temp->ants + temp->length;
	while (temp && temp->ants + temp->length == t)
		temp = temp->next;
	if (!temp)
		return (0);
	return (temp->length - t);
}

void		sort_paths(t_path *paths)
{
	t_path	*temp;
	t_pnode	*swap;
	int		s;

	temp = paths;
	while (temp->next)
	{
		if (temp->length > temp->next->length)
		{
			swap = temp->path;
			s = temp->length;
			temp->path = temp->next->path;
			temp->length = temp->next->length;
			temp->next->path = swap;
			temp->next->length = s;
			temp = paths;
		}
		else
			temp = temp->next;
	}
}

int			shortest_queues(t_path *paths)
{
	t_path	*temp;
	int		num;
	int		ret;

	num = paths->length + paths->ants;
	ret = 0;
	temp = paths;
	while (temp)
	{
		if (temp->length + temp->ants == num)
			ret++;
		else
			break ;
		temp = temp->next;
	}
	return (ret);
}
