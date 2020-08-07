/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 18:38:20 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:11:34 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_memdel(void **ap)
{
	if (*ap == NULL)
		return ;
	free(*ap);
	*ap = NULL;
}
