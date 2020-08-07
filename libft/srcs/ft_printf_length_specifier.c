/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_length_specifier.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 20:29:22 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 20:29:23 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_length_di(int64_t *num, va_list ap, t_format *node)
{
	if (!node->length_spec)
		*num = va_arg(ap, int);
	else if (node->length_spec == 'h')
	{
		*num = va_arg(ap, int);
		*num = (short int)*num;
	}
	else if (node->length_spec == 'h' + 'h')
	{
		*num = va_arg(ap, int);
		*num = (char)*num;
	}
	else if (node->length_spec == 'l')
		*num = va_arg(ap, int64_t);
	else if (node->length_spec == 'l' + 'l')
		*num = va_arg(ap, int64_t);
}

void	ft_printf_length_ouxx(u_int64_t *num, va_list ap,
t_format *node)
{
	if (!node->length_spec)
		*num = va_arg(ap, unsigned int);
	else if (node->length_spec == 'h')
	{
		*num = va_arg(ap, int);
		*num = (unsigned short int)*num;
	}
	else if (node->length_spec == 'h' + 'h')
	{
		*num = va_arg(ap, int);
		*num = (unsigned char)*num;
	}
	else if (node->length_spec == 'l')
		*num = va_arg(ap, u_int64_t);
	else if (node->length_spec == 'l' + 'l')
		*num = va_arg(ap, u_int64_t);
}

void	ft_printf_length_f(long double *num, va_list ap, t_format *node)
{
	if (!node->length_spec)
		*num = va_arg(ap, double);
	else if (node->length_spec == 'l')
		*num = va_arg(ap, double);
	else if (node->length_spec == 'L')
		*num = va_arg(ap, long double);
}
