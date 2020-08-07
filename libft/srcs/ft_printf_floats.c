/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_floats.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/03 16:51:47 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 16:15:09 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_newfloatstruct(uint16_t exponent,
		size_t size, t_floatstruct **f)
{
	(*f)->bin_integral = ft_printf_newzerostring(size);
	(*f)->dec_integral = ft_printf_newzerostring(size);
	(*f)->bin_fractional = ft_printf_newzerostring(size);
	(*f)->dec_fractional = ft_printf_newzerostring(size);
	if (!(*f)->dec_integral || !(*f)->bin_integral || !(*f)->dec_fractional ||
	!(*f)->bin_fractional)
		return ;
	(*f)->exponent = exponent - 16382;
	(*f)->bin_ilen = 1;
	(*f)->bin_flen = 1;
	(*f)->dec_ilen = 0;
	(*f)->dec_flen = 0;
}

void	ft_printf_freefloatstruct(t_floatstruct **f)
{
	free((*f)->bin_integral);
	free((*f)->dec_integral);
	free((*f)->bin_fractional);
	free((*f)->dec_fractional);
}

int		ft_printf_isfloatexception(uint16_t sign, uint16_t exponent,
u_int64_t fractional, t_format *node)
{
	if (exponent == 32767)
	{
		node->len = 3;
		node->max_width = 0;
		node->zero_flag = 0;
		if (fractional != 9223372036854775808ULL)
			node->plus_flag = 0;
		ft_printf_buffer_flags(node);
		if (sign == 1 && fractional == 9223372036854775808ULL)
			ft_printf_buffer_string("inf", 4, node);
		else if (sign == 0 && fractional == 9223372036854775808ULL)
			ft_printf_buffer_string("inf", 4, node);
		else if (fractional > 0)
			ft_printf_buffer_string("nan", 4, node);
		ft_printf_buffer_flags(node);
		return (1);
	}
	return (0);
}
