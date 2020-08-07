/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_buffer_flags.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 20:50:23 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 20:50:25 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_buffer_prefix(t_format *node)
{
	if (node->hash_flag && node->spec != 'f')
	{
		if (node->spec == 'x')
			ft_printf_buffer_string("0x", 3, node);
		else if (node->spec == 'X')
			ft_printf_buffer_string("0X", 3, node);
		else if (node->spec == 'p')
			ft_printf_buffer_string("0x", 3, node);
		else if (node->spec == 'o')
			ft_printf_buffer_character('0', node);
		node->hash_flag = 0;
	}
}

void	ft_printf_buffer_minusflag(t_format *node)
{
	if (node->blank_flag)
		ft_printf_buffer_blankspace(node);
	if (node->plus_flag)
		ft_printf_buffer_plussign(node);
	if (node->minus_sign)
		ft_printf_buffer_minussign(node);
	if (node->hash_flag)
		ft_printf_buffer_prefix(node);
	if (node->spec == 'd' || node->spec == 'i' || node->spec == 'o' ||
	node->spec == 'u' || node->spec == 'x' || node->spec == 'X')
	{
		while (node->max_width > node->len)
		{
			ft_printf_buffer_character('0', node);
			node->max_width--;
			node->min_width--;
		}
	}
}

void	ft_printf_buffer_minussign(t_format *node)
{
	if (node->minus_sign)
	{
		ft_printf_buffer_character('-', node);
		node->minus_sign = 0;
	}
}

void	ft_printf_buffer_plussign(t_format *node)
{
	if (node->plus_flag)
	{
		ft_printf_buffer_character('+', node);
		node->plus_flag = 0;
	}
}

void	ft_printf_buffer_blankspace_min(t_format *node)
{
	if ((node->minus_flag && node->min_width > node->len) ||
	(node->min_width <= node->len) || (!node->min_width) ||
	(node->min_width <= node->len) || (node->max_width > node->len) ||
	(node->zero_flag && node->len < node->min_width))
		node->min_width--;
}
