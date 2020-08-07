/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_stringcalc.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 17:12:14 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 16:13:06 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_stringmultiplication(t_floatstruct **f, char add)
{
	size_t		i;
	char		value;
	char		carry;

	i = FLOATSTR_SIZE - 1;
	carry = 0;
	while (i > 0)
	{
		value = ((*f)->dec_integral[i] - '0') * 2 + add + carry;
		if (value < 10)
		{
			(*f)->dec_integral[i] = value + '0';
			carry = 0;
			add = 0;
		}
		else
		{
			(*f)->dec_integral[i] = value % 10 + '0';
			carry = value / 10;
			add = 0;
		}
		i--;
	}
}

void	ft_printf_stringdivision(t_floatstruct **f, char add, size_t numofdiv)
{
	size_t	i;
	char	value;
	char	carry;

	carry = 0;
	i = 0;
	while (i < numofdiv)
	{
		value = ((*f)->dec_fractional[i] - '0') * 10 / 2;
		(*f)->dec_fractional[i] = (value / 10) + carry + add + '0';
		add = 0;
		carry = value % 10;
		i++;
	}
}

void	ft_printf_integraladdition(t_floatstruct **f)
{
	size_t	i;
	char	value;
	char	carry;
	char	add;

	i = FLOATSTR_SIZE;
	value = 0;
	carry = 0;
	add = 1;
	while (i > 0)
	{
		i--;
		value = (*f)->dec_integral[i] + carry + add - '0';
		carry = 0;
		add = 0;
		if (value > 9)
		{
			carry = value / 10;
			(*f)->dec_integral[i] = value % 10 + '0';
		}
		else
			(*f)->dec_integral[i] = value + '0';
	}
}

void	ft_printf_fractionaladdition(t_floatstruct **f, uint16_t len)
{
	char	value;
	char	carry;
	char	add;

	value = 0;
	carry = 0;
	add = 1;
	while (len)
	{
		len--;
		value = (*f)->dec_fractional[len] + carry + add - '0';
		add = 0;
		carry = 0;
		if (value > 9)
		{
			carry = value / 10;
			(*f)->dec_fractional[len] = value % 10 + '0';
		}
		else
			(*f)->dec_fractional[len] = value + '0';
	}
	if ((*f)->dec_fractional[0] == '0' && carry)
		ft_printf_integraladdition(f);
}

char	*ft_printf_newzerostring(size_t size)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * size + 1);
	if (!s)
		return (NULL);
	s[size] = '\0';
	while (size)
	{
		size--;
		s[size] = '0';
	}
	return (s);
}
