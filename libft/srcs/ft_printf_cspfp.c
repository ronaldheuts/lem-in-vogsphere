/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_cspfp.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 20:18:42 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 20:18:42 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_character(va_list ap, t_format *node)
{
	node->len = 1;
	ft_printf_buffer_flags(node);
	ft_printf_buffer_character(va_arg(ap, int), node);
	ft_printf_buffer_flags(node);
}

void	ft_printf_string(va_list ap, t_format *node)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	node->len = (int)ft_strlen(str);
	if (node->plus_flag)
		node->plus_flag = 0;
	if (node->precision && node->len > node->max_width)
		node->len = node->max_width;
	else if (node->precision && node->len < node->max_width)
		node->max_width = node->len;
	if (!*str)
		node->min_width += node->max_width;
	ft_printf_buffer_flags(node);
	ft_printf_buffer_string(str, node->len, node);
	ft_printf_buffer_flags(node);
}

void	ft_printf_pointer(va_list ap, t_format *node)
{
	u_int64_t	tmp;

	tmp = (u_int64_t)va_arg(ap, void *);
	node->hash_flag = 1;
	ft_printf_len_base_unsigned(tmp, 16, node);
	ft_printf_buffer_flags(node);
	ft_printf_lltoa_base_unsigned(tmp, 16, 87, node);
	ft_printf_buffer_flags(node);
}

void	ft_printf_float(va_list ap, t_format *node)
{
	long double	tmp;
	long double	*ptr_tmp;

	ptr_tmp = &tmp;
	if (node->zero_flag && node->minus_flag)
		node->zero_flag = 0;
	ft_printf_length_f(ptr_tmp, ap, node);
	if (tmp < 0)
	{
		node->minus_sign = 1;
		node->sign = 1;
		node->plus_flag = 0;
		node->min_width--;
	}
	else if (node->plus_flag)
		node->min_width--;
	ft_printf_floattoa(tmp, node);
}

void	ft_printf_percent(t_format *node)
{
	node->len = 1;
	if (node->plus_flag)
		node->plus_flag = 0;
	if (node->max_width)
		node->max_width = 0;
	ft_printf_buffer_flags(node);
	ft_printf_buffer_character('%', node);
	ft_printf_buffer_flags(node);
}
