/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_binaryconv.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 17:16:11 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 16:12:08 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_decimaltobinarystring(t_floatstruct **f, u_int64_t number)
{
	size_t	i;

	i = FRACTIONAL_64;
	while (i)
	{
		i--;
		if (number % 2 == 1)
			(*f)->bin_fractional[i] = '1';
		else
			(*f)->bin_fractional[i] = '0';
		number /= 2;
	}
}

void	ft_printf_binaryintegraltoa(t_floatstruct **f)
{
	size_t		i;

	i = FLOATSTR_SIZE - (*f)->bin_ilen;
	while (i < FLOATSTR_SIZE)
	{
		if ((*f)->bin_integral[i] == '1')
			ft_printf_stringmultiplication(f, 1);
		else
			ft_printf_stringmultiplication(f, 0);
		i++;
	}
}

void	ft_printf_binaryfractionaltoa(t_floatstruct **f)
{
	size_t		i;

	i = 0;
	while ((*f)->bin_flen > i)
	{
		if ((*f)->bin_fractional[(*f)->bin_flen - 1 - i] == '1')
			ft_printf_stringdivision(f, 5, i + 1);
		else
			ft_printf_stringdivision(f, 0, i + 1);
		i++;
	}
}

size_t	ft_printf_binarystringlen(char *fractional)
{
	size_t	i;
	size_t	bin_flen;

	i = 0;
	bin_flen = 0;
	while (fractional[i])
	{
		if (fractional[i] == '1')
			bin_flen = i;
		i++;
	}
	return (bin_flen + 1);
}
