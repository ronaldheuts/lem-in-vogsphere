/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validatemap.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:32:31 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 18:38:15 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		validatemap(t_data *lemin)
{
	if (!isants(lemin))
	{
		ft_printf("[Error] Missing ants or incomplete map\n");
		return (0);
	}
	if (!loadrooms(lemin))
		return (0);
	if (!lemin->start)
	{
		ft_printf("[Error] Missing start room\n");
		return (0);
	}
	if (!lemin->end)
	{
		ft_printf("[Error] Missing end room\n");
		return (0);
	}
	if (!loadlinks(lemin))
	{
		ft_printf("[Error] Invalid link input: %s\n", lemin->walker->line);
		return (0);
	}
	return (1);
}
