/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moveants.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:31:36 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 17:25:04 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		numswap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	getant(t_path *p_walker, int *temp_ant, int *id)
{
	if (p_walker->ants > 0)
	{
		*temp_ant = *id;
		p_walker->ants--;
		(*id)++;
	}
	else
		*temp_ant = 0;
}

static void	sendants(t_data *lemin, t_path *p_walker, int *id)
{
	t_pnode	*r_walker;
	int		temp_ant;

	r_walker = p_walker->path;
	temp_ant = 0;
	if (p_walker->ants > 0)
		getant(p_walker, &temp_ant, id);
	while (r_walker)
	{
		numswap(&temp_ant, &r_walker->ant_id);
		if (r_walker->next == NULL)
			break ;
		r_walker = r_walker->next;
	}
	while (r_walker)
	{
		if (r_walker->ant_id)
			ft_printf("L%i-%s ", r_walker->ant_id, r_walker->room->name);
		if (r_walker->room == lemin->end && r_walker->ant_id > 0)
			lemin->ants--;
		r_walker = r_walker->prev;
	}
}

void		moveants(t_data *lemin)
{
	t_path	*p_walker;
	int		id;

	id = 1;
	while (lemin->ants > 0)
	{
		p_walker = lemin->paths;
		while (p_walker)
		{
			sendants(lemin, p_walker, &id);
			p_walker = p_walker->next;
		}
		ft_printf("\n");
	}
}
