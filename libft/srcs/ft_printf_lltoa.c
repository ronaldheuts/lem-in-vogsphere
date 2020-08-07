/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_lltoa.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 19:59:39 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 19:59:39 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	uppercase = 55
**	lowercase = 87
*/

int		ft_printf_lltoa_exceptions(int64_t num, t_format *node)
{
	if (node->precision && !node->max_width && node->spec != 'f')
		if (!num)
			return (1);
	if (num == (-9223372036854775807 - 1))
	{
		if ((!node->zero_flag) && node->minus_sign &&
		(node->max_width < node->len))
		{
			ft_printf_buffer_character('-', node);
			node->minus_sign = 0;
		}
		ft_printf_buffer_string("9223372036854775808", 20, node);
		return (1);
	}
	return (0);
}

int		ft_printf_lltoa_base(int64_t num, int64_t base,
int ulcase, t_format *node)
{
	if (ft_printf_lltoa_exceptions(num, node))
		return (0);
	if (num < 0)
		num *= -1;
	if (num < base)
	{
		if (ft_isdigit(num % base + 48))
			ft_printf_buffer_character(num % base + 48, node);
		else
			ft_printf_buffer_character(num % base + ulcase, node);
	}
	if (num >= base)
	{
		ft_printf_lltoa_base(num / base, base, ulcase, node);
		if (ft_isdigit(num % base + 48))
			ft_printf_buffer_character(num % base + 48, node);
		else
			ft_printf_buffer_character(num % base + ulcase, node);
	}
	return (0);
}

int		ft_printf_lltoa_base_unsigned(u_int64_t num,
u_int64_t base, int ulcase, t_format *node)
{
	if ((node->precision && !node->prefix) || (node->precision &&
	node->prefix && (node->spec == 'u' || node->spec == 'o' ||
	node->spec == 'x' || node->spec == 'X')))
	{
		if (!num)
			return (0);
	}
	if (num < base)
	{
		if (ft_isdigit(num % base + 48))
			ft_printf_buffer_character(num % base + 48, node);
		else
			ft_printf_buffer_character(num % base + ulcase, node);
	}
	if (num >= base)
	{
		ft_printf_lltoa_base_unsigned(num / base, base, ulcase, node);
		if (ft_isdigit(num % base + 48))
			ft_printf_buffer_character(num % base + 48, node);
		else
			ft_printf_buffer_character(num % base + ulcase, node);
	}
	return (0);
}

void	ft_printf_floattoa(long double number, t_format *node)
{
	t_floatunion	efloat;
	t_floatstruct	*f;

	efloat.value = number;
	if (!ft_printf_isfloatexception(efloat.t_bits.sign, efloat.t_bits.exponent,
	efloat.t_bits.fractional, node))
	{
		f = (t_floatstruct *)malloc(sizeof(t_floatstruct));
		if (!f)
			return ;
		ft_printf_newfloatstruct(efloat.t_bits.exponent, FLOATSTR_SIZE, &f);
		ft_printf_decimaltobinarystring(&f, efloat.t_bits.fractional);
		f->bin_flen = ft_printf_binarystringlen(f->bin_fractional);
		ft_printf_bitmove(&f);
		ft_printf_dectrim(&f, node);
		ft_printf_buffer_flags(node);
		ft_printf_buffer_string(f->dec_integral, f->dec_ilen, node);
		if (node->max_width || node->hash_flag)
			ft_printf_buffer_character('.', node);
		ft_printf_buffer_string(f->dec_fractional, node->max_width, node);
		ft_printf_buffer_flags(node);
		ft_printf_freefloatstruct(&f);
		free(f);
	}
}
