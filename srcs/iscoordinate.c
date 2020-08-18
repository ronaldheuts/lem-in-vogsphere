/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iscoordinate.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 17:51:23 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/18 11:11:25 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		iscoordinate(char *s, int *i)
{
	long long	n;

	if (!s)
		return (0);
	n = ft_atoll(s + *i);
	if (n > INT32_MAX || n < 0)
		return (0);
	if (s[*i] != ' ')
		return (0);
	(*i)++;
	if (!ft_isdigit(s[*i]))
		return (0);
	while (s[*i] && s[*i] != ' ')
	{
		if (!ft_isdigit(s[*i]))
			return (0);
		(*i)++;
	}
	return (1);
}
