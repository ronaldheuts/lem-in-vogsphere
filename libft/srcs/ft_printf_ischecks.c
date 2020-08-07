/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_ischecks.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 19:59:25 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 19:59:26 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_isconversion(const char spec, t_format *node)
{
	if (spec == 'c' || spec == 's' || spec == 'p' || spec == 'd' ||
	spec == 'i' || spec == 'o' || spec == 'u' || spec == 'x' || spec == 'X' ||
	spec == 'f' || spec == '%')
	{
		if (!node->spec)
			node->spec = spec;
		return (1);
	}
	else
		return (0);
}

int	ft_printf_isflag(const char format, t_format *node)
{
	if (format == '#' || format == '0' || format == '-' || format == ' ' ||
	format == '+')
	{
		if (format == '#')
		{
			node->hash_flag = 1;
			node->prefix = 1;
		}
		else if (format == '0')
			node->zero_flag = 1;
		else if (format == '-')
			node->minus_flag = 1;
		else if (format == ' ')
			node->blank_flag = 1;
		else if (format == '+')
		{
			node->plus_flag = 1;
			node->sign = 1;
		}
		return (1);
	}
	else
		return (0);
}
