/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_binstrfun.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 17:19:06 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 16:13:57 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_bitswap(char *a, char *b)
{
	char	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_printf_ft_printf_bitmoveright(t_floatstruct **f)
{
	size_t		i;
	uint16_t	exponent;

	i = FRACTIONAL_64;
	exponent = (*f)->exponent * -1;
	while (i > 0)
	{
		i--;
		ft_printf_bitswap(&(*f)->bin_fractional[i + exponent],
		&(*f)->bin_fractional[i]);
		(*f)->bin_fractional[i] = '0';
	}
}

void	ft_printf_ft_printf_bitmoveleft(t_floatstruct **f)
{
	size_t	i;
	size_t	j;

	i = FLOATSTR_SIZE - (*f)->exponent;
	j = 0;
	while (i + j < FLOATSTR_SIZE)
	{
		ft_printf_bitswap(&(*f)->bin_integral[i + j],
		&(*f)->bin_fractional[j]);
		j++;
	}
	j = 0;
	while (j < (*f)->bin_flen + 1)
	{
		ft_printf_bitswap(&(*f)->bin_fractional[j],
		&(*f)->bin_fractional[j + (*f)->exponent]);
		j++;
	}
}

void	ft_printf_bitmove(t_floatstruct **f)
{
	if ((*f)->exponent > 0)
		ft_printf_ft_printf_bitmoveleft(f);
	else if ((*f)->exponent < 0)
		ft_printf_ft_printf_bitmoveright(f);
	(*f)->bin_ilen = 1 + (*f)->exponent;
	(*f)->bin_flen = ft_printf_binarystringlen((*f)->bin_fractional);
	ft_printf_binaryfractionaltoa(f);
	ft_printf_binaryintegraltoa(f);
}
