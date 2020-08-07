/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 13:49:17 by anonymous     #+#    #+#                 */
/*   Updated: 2020/08/07 17:14:53 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	print_input(t_data *lemin)
{
	t_line	*walker;

	walker = lemin->map->head;
	while (walker)
	{
		ft_putendl(walker->line);
		walker = walker->next;
	}
	ft_putendl("");
}

int		check_input(t_map *input, t_data **lemin)
{
	if (!loadmap(input))
	{
		freemap(input);
		ft_printf("[Error] Empty map\n");
		return (0);
	}
	countrooms(input);
	*lemin = newlemin(input);
	if (!lemin)
	{
		freelemin(lemin);
		return (0);
	}
	if (!validatemap(*lemin))
	{
		freelemin(lemin);
		return (0);
	}
	return (1);
}
