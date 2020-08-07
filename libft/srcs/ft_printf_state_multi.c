/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_state_multi.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 20:00:02 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 20:00:03 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_state_flags(const char **format, t_format *node)
{
	while (**format && ft_printf_isflag(**format, node))
	{
		ft_printf_isflag(**format, node);
		(*format)++;
	}
}

void	ft_printf_state_minwidth(const char **format, t_format *node)
{
	if (ft_isdigit(**format))
	{
		node->min_width = ft_atoi(*format);
		while (**format && ft_isdigit(**format))
			(*format)++;
	}
}

void	ft_printf_state_precision(const char **format, t_format *node)
{
	if (**format == '.')
	{
		node->precision = 1;
		(*format)++;
		if (ft_isdigit(**format))
		{
			node->max_width = ft_atoi(*format);
			while (**format && ft_isdigit(**format))
				(*format)++;
		}
	}
}

void	ft_printf_state_length(const char **format, t_format *node)
{
	while ((**format == 'h') && (!node->length_spec ||
	node->length_spec == 'h'))
	{
		node->length_spec += 'h';
		(*format)++;
	}
	while ((**format == 'l') && (!node->length_spec ||
	node->length_spec == 'l'))
	{
		node->length_spec += 'l';
		(*format)++;
	}
	if (**format == 'L' && !node->length_spec)
	{
		(*format)++;
		node->length_spec = 'L';
	}
}

void	ft_printf_state_spec(const char **format, va_list ap,
t_ptrfun *fun_array, t_format *node)
{
	if (ft_printf_isconversion(**format, node))
	{
		if (!node->precision && !node->max_width && node->spec == 'f')
			node->max_width = 6;
		if (**format == '%')
			ft_printf_percent(node);
		else if (**format != '%')
			fun_array[**format - 'A'](ap, node);
		(*format)++;
		if (node->colour)
			ft_printf_buffer_string("\033[0m", 5, node);
		ft_printf_reset_node(node);
	}
}
