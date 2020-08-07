/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 16:31:46 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:12:36 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
**	Returns '1' if the two strings are identical, else '0'.
*/

int			ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
