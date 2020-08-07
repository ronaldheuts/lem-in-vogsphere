/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gethash.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 14:29:57 by rheuts        #+#    #+#                 */
/*   Updated: 2020/07/29 17:49:17 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** The hash algorithm used is named 'djb2' designed by Dan Bernstein.
** The bit operation is equal to: hash * 33 + *s.
*/

unsigned int	hash(char *s, int n_rooms)
{
	unsigned int	hash;

	hash = 5381;
	while (*s)
	{
		hash = ((hash << 5) + hash) + (unsigned char)*s;
		s++;
	}
	return (hash % n_rooms);
}
