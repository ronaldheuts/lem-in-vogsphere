/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/02 18:44:00 by rheuts        #+#    #+#                 */
/*   Updated: 2019/10/02 18:44:00 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_sprintf(char *str, const char *format, ...)
{
	int			total;
	va_list		ap;
	t_format	*node;
	t_ptrfun	fun_array[57];
	const char	**ptr_fmt;

	ptr_fmt = &format;
	node = (t_format *)malloc(sizeof(t_format));
	if (!node)
		return (-1);
	ft_printf_ini_fun(fun_array);
	ft_printf_ini_node(1, node);
	node->str = str;
	va_start(ap, format);
	ft_printf_state_base(ptr_fmt, ap, fun_array, node);
	if (node->index)
		ft_printf_end_of_format(node);
	va_end(ap);
	total = node->total;
	free(node);
	return (total);
}

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	int			total;
	va_list		ap;
	t_format	*node;
	t_ptrfun	fun_array[57];
	const char	**ptr_fmt;

	ptr_fmt = &format;
	node = (t_format *)malloc(sizeof(t_format));
	if (!node)
		return (-1);
	ft_printf_ini_fun(fun_array);
	ft_printf_ini_node(1, node);
	node->size = size - 1;
	node->str = str;
	va_start(ap, format);
	ft_printf_state_base(ptr_fmt, ap, fun_array, node);
	if (node->index)
		ft_printf_end_of_format(node);
	va_end(ap);
	total = node->total;
	free(node);
	return (total);
}

int		ft_printf(const char *format, ...)
{
	int			total;
	va_list		ap;
	t_format	*node;
	t_ptrfun	fun_array[57];
	const char	**ptr_fmt;

	ptr_fmt = &format;
	node = (t_format *)malloc(sizeof(t_format));
	if (!node)
		return (-1);
	ft_printf_ini_fun(fun_array);
	ft_printf_ini_node(1, node);
	va_start(ap, format);
	ft_printf_state_base(ptr_fmt, ap, fun_array, node);
	if (node->index)
		ft_printf_end_of_format(node);
	va_end(ap);
	total = node->total;
	free(node);
	return (total);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	int			total;
	va_list		ap;
	t_format	*node;
	t_ptrfun	fun_array[57];
	const char	**ptr_fmt;

	ptr_fmt = &format;
	node = (t_format *)malloc(sizeof(t_format));
	if (!node)
		return (-1);
	ft_printf_ini_fun(fun_array);
	ft_printf_ini_node(fd, node);
	va_start(ap, format);
	ft_printf_state_base(ptr_fmt, ap, fun_array, node);
	if (node->index)
		ft_printf_end_of_format(node);
	va_end(ap);
	total = node->total;
	free(node);
	return (total);
}
