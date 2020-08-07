/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 20:02:12 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 20:02:12 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_len_prefix(t_format *node)
{
	if (node->hash_flag)
	{
		if (node->spec == 'x' || node->spec == 'X' || node->spec == 'p')
			node->min_width -= 2;
		else if (node->spec == 'o')
			node->len++;
	}
}

void	ft_printf_len_sign(int64_t num, t_format *node)
{
	if (num < 0)
	{
		node->minus_sign = 1;
		node->sign = 1;
		node->plus_flag = 0;
		node->min_width--;
	}
	else if (node->plus_flag)
		node->min_width--;
}

void	ft_printf_len_base(int64_t num, int base, t_format *node)
{
	int64_t	cpy;

	cpy = num;
	ft_printf_len_prefix(node);
	if (!cpy && !node->precision && node->spec != 'f')
		node->len++;
	while (cpy)
	{
		cpy = cpy / base;
		node->len++;
	}
	if (node->spec != 'f')
		ft_printf_len_sign(num, node);
}

void	ft_printf_len_base_unsigned(u_int64_t num, int base,
t_format *node)
{
	if (!num && (node->spec != 'p' && node->spec != 'o'))
		node->hash_flag = 0;
	if (!num && node->hash_flag && node->max_width && node->spec == 'o')
		node->hash_flag = 0;
	if ((!num && !node->precision) && (node->spec != 'p' || node->spec == 'f'))
		node->len++;
	if (!num && node->spec == 'p')
		node->min_width--;
	if (node->hash_flag)
		ft_printf_len_prefix(node);
	while (num)
	{
		num = num / base;
		node->len++;
	}
}
