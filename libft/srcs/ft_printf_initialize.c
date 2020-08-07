/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_initialize.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/01 19:59:13 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/01 19:59:15 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_ini_fun(t_ptrfun fun_array[57])
{
	int		i;

	i = 0;
	while (i < 57)
	{
		fun_array[i] = NULL;
		i++;
	}
	fun_array[34] = &ft_printf_character;
	fun_array[50] = &ft_printf_string;
	fun_array[47] = &ft_printf_pointer;
	fun_array[35] = &ft_printf_decimal;
	fun_array[40] = &ft_printf_decimal;
	fun_array[46] = &ft_printf_octal;
	fun_array[52] = &ft_printf_unsigned;
	fun_array[55] = &ft_printf_hexadecimal;
	fun_array[23] = &ft_printf_hexadecimal;
	fun_array[37] = &ft_printf_float;
}

void	ft_printf_ini_node(int fd, t_format *node)
{
	node->str = NULL;
	node->size = 0;
	node->index = 0;
	node->total = 0;
	node->hash_flag = 0;
	node->zero_flag = 0;
	node->minus_flag = 0;
	node->blank_flag = 0;
	node->plus_flag = 0;
	node->min_width = 0;
	node->max_width = 0;
	node->len = 0;
	node->sign = 0;
	node->minus_sign = 0;
	node->precision = 0;
	node->prefix = 0;
	node->colour = 0;
	node->spec = 0;
	node->length_spec = 0;
	node->fd = fd;
}

void	ft_printf_reset_node(t_format *node)
{
	node->hash_flag = 0;
	node->zero_flag = 0;
	node->minus_flag = 0;
	node->blank_flag = 0;
	node->plus_flag = 0;
	node->min_width = 0;
	node->max_width = 0;
	node->len = 0;
	node->sign = 0;
	node->minus_sign = 0;
	node->precision = 0;
	node->prefix = 0;
	node->colour = 0;
	node->spec = 0;
	node->length_spec = 0;
}
