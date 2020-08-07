/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 13:50:11 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/07 18:25:34 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long	ft_atoll(const char *str)
{
	long long	result;
	char		sign;

	result = 0;
	sign = 1;
	if (!str)
		return (0);
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') && (*str != '\0'))
	{
		result = (result * 10) + (*str - 48);
		if (result > INT32_MAX || result < INT32_MIN)
			break ;
		str++;
	}
	return (result * sign);
}
