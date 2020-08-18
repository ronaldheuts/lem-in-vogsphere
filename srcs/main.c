/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 17:57:25 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/18 12:32:25 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <fcntl.h>
#include <sys/stat.h>

int		main(void)
{
	t_data	*lemin;
	t_map	*input;

	input = newmap();
	if (!check_input(input, &lemin))
		exit (0);
	clean_map(lemin);
	algorithm(lemin);
	if (lemin->max < 1 || !get_path_data(lemin->paths->path))
	{
		ft_putendl("[Error] No path available");
		exit(0);
	}
	print_input(lemin);
	moveants(lemin);
	free_path(lemin->paths);
	freelemin(&lemin);
	return (0);
}
