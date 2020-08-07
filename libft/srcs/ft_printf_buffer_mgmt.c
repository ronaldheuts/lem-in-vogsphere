/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_buffer_mgmt.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 14:40:56 by rheuts        #+#    #+#                 */
/*   Updated: 2019/12/04 14:40:57 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_buffer_character(const unsigned char c, t_format *node)
{
	if (!node->str && !node->size)
	{
		if (node->index == BUFFER_SIZE)
		{
			write(node->fd, node->buffer, BUFFER_SIZE);
			node->total += BUFFER_SIZE;
			node->index = 0;
		}
		node->buffer[node->index] = c;
		node->index++;
	}
	else if (node->str && !node->size)
	{
		node->str[node->index] = c;
		node->index++;
	}
	else if (node->str && node->size)
	{
		if (node->size > node->index)
		{
			node->str[node->index] = c;
			node->index++;
		}
	}
}

void	ft_printf_buffer_string(const char *s, int len, t_format *node)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		ft_printf_buffer_character(s[i], node);
		i++;
	}
}

void	ft_printf_end_of_format(t_format *node)
{
	if (!node->str)
		write(node->fd, node->buffer, node->index);
	node->total += node->index;
}
