/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   isants.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:30:09 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 18:13:45 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		isants(t_data *lemin)
{
	int	i;

	i = 0;
	if (!lemin->walker || !lemin->walker->line)
		return (0);
	while (lemin->walker && iscomment(lemin->walker->line))
		lemin->walker = lemin->walker->next;
	if (!lemin->walker)
		return (0);
	while (lemin->walker && lemin->walker->line[i])
	{
		if (!ft_isdigit(lemin->walker->line[i]))
			return (0);
		i++;
	}
	lemin->ants = ft_atoll(lemin->walker->line);
	if (lemin->ants <= 0 || lemin->ants > INT32_MAX)
		return (0);
	if (lemin->walker)
		lemin->walker = lemin->walker->next;
	return (1);
}
