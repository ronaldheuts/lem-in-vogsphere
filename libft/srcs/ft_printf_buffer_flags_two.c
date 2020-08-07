/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_buffer_flags_two.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 17:03:13 by rheuts        #+#    #+#                 */
/*   Updated: 2019/11/27 17:03:14 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_buffer_blankspace(t_format *node)
{
	if ((node->spec == 'd' || node->spec == 'i' || node->spec == 'f')
	&& node->blank_flag && !node->sign)
	{
		if (node->minus_flag)
		{
			if (node->minus_flag && node->min_width > node->len)
				ft_printf_buffer_character(' ', node);
			else if (node->min_width <= node->len)
				ft_printf_buffer_character(' ', node);
		}
		else
		{
			if (!node->min_width)
				ft_printf_buffer_character(' ', node);
			else if (node->min_width <= node->len)
				ft_printf_buffer_character(' ', node);
			else if (node->max_width > node->len)
				ft_printf_buffer_character(' ', node);
			else if (node->zero_flag && node->len < node->min_width)
				ft_printf_buffer_character(' ', node);
		}
		ft_printf_buffer_blankspace_min(node);
		node->blank_flag = 0;
	}
}

void	printf_minwidth(t_format *node)
{
	if (node->blank_flag)
		ft_printf_buffer_blankspace(node);
	if (node->hash_flag && (node->zero_flag || node->max_width > node->len))
		ft_printf_buffer_prefix(node);
	while (node->min_width && node->min_width > node->max_width &&
	node->min_width > node->len)
	{
		if (node->zero_flag && (!node->max_width || node->spec == 'f'))
			ft_printf_buffer_character('0', node);
		else
			ft_printf_buffer_character(' ', node);
		node->min_width--;
	}
	node->min_width = 0;
}

void	printf_maxwidth(t_format *node)
{
	if ((node->max_width) && (node->spec == 'd' || node->spec == 'i'
	|| node->spec == 'o' || node->spec == 'u' || node->spec == 'p'
	|| node->spec == 'x' || node->spec == 'X'))
	{
		while (node->max_width > node->len)
		{
			ft_printf_buffer_character('0', node);
			node->max_width--;
		}
	}
}

int		ft_printf_buffer_flags(t_format *node)
{
	if (node->minus_flag)
	{
		ft_printf_buffer_minusflag(node);
		node->minus_flag = 0;
		return (0);
	}
	if ((node->plus_flag && node->zero_flag) && ((node->max_width >
	node->min_width) || (!node->max_width && node->min_width > node->len)))
		ft_printf_buffer_plussign(node);
	else if ((node->minus_sign && node->zero_flag) && ((node->max_width >
	node->min_width) || (!node->max_width && node->min_width > node->len)))
		ft_printf_buffer_minussign(node);
	printf_minwidth(node);
	if (node->plus_flag)
		ft_printf_buffer_plussign(node);
	else if (node->minus_sign)
		ft_printf_buffer_minussign(node);
	printf_maxwidth(node);
	ft_printf_buffer_prefix(node);
	return (0);
}
