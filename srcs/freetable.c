/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freetable.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:30 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 14:38:27 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	freetable(t_room **hashtable, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (hashtable[i])
			freelist(&hashtable[i]);
		hashtable[i] = NULL;
		i++;
	}
	ft_memdel((void **)&hashtable);
}
