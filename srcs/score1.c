/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   score1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-hou <mvan-hou@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/03 16:53:35 by mvan-hou      #+#    #+#                 */
/*   Updated: 2020/08/03 17:05:50 by mvan-hou      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			get_score(t_path *paths)
{
	int		max;
	t_path	*temp;

	max = 0;
	temp = paths;
	while (temp)
	{
		if (temp->length + temp->ants > max && temp->ants > 0)
			max = temp->length + temp->ants;
		temp = temp->next;
	}
	return (max);
}

int			count_paths(t_path *paths)
{
	t_path	*temp;
	int		count;

	temp = paths;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int			calculate_score(t_path *paths, t_data *lemin)
{
	int		count;

	count = count_paths(paths);
	sort_paths(paths);
	distribute_ants(paths, count, lemin->ants);
	return (get_score(paths));
}

void		free_path(t_path *paths)
{
	t_path	*fpath;
	t_path	*tpath;
	t_pnode	*fnode;
	t_pnode	*tnode;

	if (!paths)
		return ;
	fpath = paths;
	while (fpath)
	{
		fnode = fpath->path;
		while (fnode)
		{
			tnode = fnode->next;
			free(fnode);
			fnode = tnode;
		}
		tpath = fpath->next;
		free(fpath);
		fpath = tpath;
	}
}

t_path		*compare(t_data *lemin)
{
	int		new_score;
	int		p_id;
	t_path	*new_path;

	p_id = 0;
	if (lemin->paths == NULL)
	{
		new_path = get_paths(lemin, p_id);
		lemin->score = calculate_score(new_path, lemin);
		return (new_path);
	}
	if (lemin->score == 0)
		lemin->score = calculate_score(lemin->paths, lemin);
	new_path = get_paths(lemin, p_id);
	new_score = calculate_score(new_path, lemin);
	if (new_score < lemin->score)
	{
		lemin->score = new_score;
		free_path(lemin->paths);
		return (new_path);
	}
	free_path(new_path);
	return (lemin->paths);
}
