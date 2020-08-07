/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_dectrim.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 18:29:57 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 16:14:35 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_printf_rounding(t_floatstruct **f, t_format *node)
{
	size_t	i;

	i = (size_t)node->max_width;
	if (i == 0 && (*f)->dec_fractional[0] >= '5')
		ft_printf_integraladdition(f);
	if ((*f)->dec_fractional[i] >= '5')
		ft_printf_fractionaladdition(f, i);
}

void	ft_printf_decintegraltrim(t_floatstruct **f)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (!((*f)->dec_integral[i] >= '1' && (*f)->dec_integral[i] <= '9') &&
	(*f)->dec_integral[i])
		i++;
	(*f)->dec_ilen = i;
	if (i == FLOATSTR_SIZE && (*f)->dec_integral[i - 1] == '0')
	{
		temp = ft_strdup("0");
		(*f)->dec_ilen = 1;
	}
	else
		temp = ft_strdup((*f)->dec_integral + i);
	free((*f)->dec_integral);
	(*f)->dec_integral = temp;
}

void	ft_printf_decfractionaltrim(t_floatstruct **f, t_format *node)
{
	size_t	i;
	char	*temp;

	i = FLOATSTR_SIZE - 1;
	while (!((*f)->dec_fractional[i] >= '1' &&
	(*f)->dec_fractional[i] <= '9') && i > 0)
		i--;
	(*f)->dec_flen = i;
	ft_printf_rounding(f, node);
	temp = ft_strndup((*f)->dec_fractional, node->max_width);
	free((*f)->dec_fractional);
	(*f)->dec_fractional = temp;
}

void	ft_printf_dectrim(t_floatstruct **f, t_format *node)
{
	ft_printf_decfractionaltrim(f, node);
	ft_printf_decintegraltrim(f);
	node->len = ft_strlen((*f)->dec_integral) + node->max_width;
	if (node->max_width || node->hash_flag)
		node->len += DECIMAL_POINT;
}
