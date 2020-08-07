/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_state_base.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 19:59:51 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 19:59:51 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf_colour_list(const char *str, t_format *node)
{
	if (!ft_strcmp(str, "default"))
		ft_printf_buffer_string("\033[0m", 5, node);
	else if (!ft_strcmp(str, "red"))
		ft_printf_buffer_string("\033[0;31m", 8, node);
	else if (!ft_strcmp(str, "green"))
		ft_printf_buffer_string("\033[0;32m", 8, node);
	else if (!ft_strcmp(str, "yellow"))
		ft_printf_buffer_string("\033[0;33m", 8, node);
	else if (!ft_strcmp(str, "blue"))
		ft_printf_buffer_string("\033[0;34m", 8, node);
	else if (!ft_strcmp(str, "magenta"))
		ft_printf_buffer_string("\033[0;35m", 8, node);
	else if (!ft_strcmp(str, "cyan"))
		ft_printf_buffer_string("\033[0;36m", 8, node);
	else
		return (0);
	return (1);
}

void	ft_printf_state_colour(const char **format, t_format *node)
{
	char	input[64];
	int		i;

	i = 0;
	if (**format == '{')
	{
		ft_memset(input, '\0', 64);
		(*format)++;
		while (**format && **format != '}' && i < 64 && ft_isalpha(**format))
		{
			input[i] = **format;
			(*format)++;
			i++;
		}
	}
	if (**format == '}')
	{
		if (ft_printf_colour_list(input, node))
			node->colour = 1;
		(*format)++;
	}
}

void	ft_printf_state_base(const char **format,
va_list ap, t_ptrfun *fun_array, t_format *node)
{
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			ft_printf_state_flags(format, node);
			ft_printf_state_minwidth(format, node);
			ft_printf_state_precision(format, node);
			ft_printf_state_colour(format, node);
			ft_printf_state_length(format, node);
			ft_printf_state_spec(format, ap, fun_array, node);
		}
		else
		{
			ft_printf_buffer_character(**format, node);
			(*format)++;
		}
	}
}
