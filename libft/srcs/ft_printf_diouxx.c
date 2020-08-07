/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_diouxx.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 20:21:05 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 20:21:06 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_ignoreflags_diouxx(t_format *node)
{
	if (node->spec == 'd' || node->spec == 'i' || node->spec == 'o' ||
	node->spec == 'u' || node->spec == 'x' || node->spec == 'X')
	{
		if (node->minus_flag)
		{
			if (node->zero_flag)
				node->zero_flag = 0;
			if (node->max_width > node->min_width)
				node->minus_flag = 0;
		}
	}
	if (node->spec == 'u')
	{
		if (node->blank_flag)
			node->blank_flag = 0;
		if (node->plus_flag)
			node->plus_flag = 0;
	}
	if (node->spec == 'o')
	{
		if (node->zero_flag && node->precision)
			node->zero_flag = 0;
	}
}

void	ft_printf_decimal(va_list ap, t_format *node)
{
	int64_t	tmp;
	int64_t	*ptr_temp;

	tmp = 0;
	ptr_temp = &tmp;
	ft_printf_length_di(ptr_temp, ap, node);
	ft_printf_len_base(tmp, 10, node);
	ft_printf_ignoreflags_diouxx(node);
	ft_printf_buffer_flags(node);
	ft_printf_lltoa_base(tmp, 10, 0, node);
	ft_printf_buffer_flags(node);
}

void	ft_printf_octal(va_list ap, t_format *node)
{
	u_int64_t	tmp;
	u_int64_t	*ptr_tmp;

	tmp = 0;
	ptr_tmp = &tmp;
	ft_printf_length_ouxx(ptr_tmp, ap, node);
	if (node->hash_flag && !tmp && !node->precision)
		node->hash_flag = 0;
	ft_printf_len_base_unsigned(tmp, 8, node);
	ft_printf_ignoreflags_diouxx(node);
	ft_printf_buffer_flags(node);
	ft_printf_lltoa_base_unsigned(tmp, 8, 0, node);
	ft_printf_buffer_flags(node);
}

void	ft_printf_unsigned(va_list ap, t_format *node)
{
	u_int64_t	tmp;
	u_int64_t	*ptr_tmp;

	tmp = 0;
	ptr_tmp = &tmp;
	ft_printf_length_ouxx(ptr_tmp, ap, node);
	ft_printf_ignoreflags_diouxx(node);
	ft_printf_len_base_unsigned(tmp, 10, node);
	ft_printf_buffer_flags(node);
	ft_printf_lltoa_base_unsigned(tmp, 10, 0, node);
	ft_printf_buffer_flags(node);
}

void	ft_printf_hexadecimal(va_list ap, t_format *node)
{
	u_int64_t	tmp;
	u_int64_t	*ptr_tmp;

	tmp = 0;
	ptr_tmp = &tmp;
	ft_printf_length_ouxx(ptr_tmp, ap, node);
	ft_printf_len_base_unsigned(tmp, 16, node);
	ft_printf_ignoreflags_diouxx(node);
	ft_printf_buffer_flags(node);
	if (node->spec == 'x')
		ft_printf_lltoa_base_unsigned(tmp, 16, 87, node);
	else if (node->spec == 'X')
		ft_printf_lltoa_base_unsigned(tmp, 16, 55, node);
	ft_printf_buffer_flags(node);
}
