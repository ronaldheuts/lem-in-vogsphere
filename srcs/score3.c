/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   score3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 16:59:33 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/08/03 17:00:06 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		divide_ants(t_path *paths, int size, int ants)
{
	t_path	*temp;
	int		div;
	int		mod;

	temp = paths;
	div = ants / size;
	mod = ants % size;
	while (size)
	{
		temp->ants += div;
		if (mod)
		{
			temp->ants += 1;
			mod--;
		}
		temp = temp->next;
		size--;
	}
}

int			level_queues(t_path *paths, int s_q, int n_q)
{
	t_path	*temp;
	int		ret;

	ret = 0;
	temp = paths;
	while (s_q)
	{
		ret += n_q;
		temp->ants += n_q;
		temp = temp->next;
		s_q--;
	}
	return (ret);
}

void		distribute_ants(t_path *paths, int count, int ants)
{
	int	t_ants;
	int next_q;
	int	short_q;

	while (ants)
	{
		short_q = shortest_queues(paths);
		next_q = next_queue_length(paths);
		t_ants = next_q * short_q;
		if (count == short_q)
		{
			divide_ants(paths, short_q, ants);
			break ;
		}
		else if (ants >= t_ants && t_ants > 0)
			ants -= level_queues(paths, short_q, next_q);
		else
		{
			divide_ants(paths, short_q, ants);
			break ;
		}
	}
}
