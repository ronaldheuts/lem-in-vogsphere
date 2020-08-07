/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rheuts <rheuts@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/22 12:40:16 by rheuts        #+#    #+#                 */
/*   Updated: 2020/08/03 17:15:24 by rheuts        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include "../includes/libft.h"

static t_list	*find_fd(const int fd, t_list **head)
{
	t_list			*current;
	t_list			*new;

	current = *head;
	while (current)
	{
		if (current->content_size == (size_t)fd)
			return (current);
		current = current->next;
	}
	if (!current)
	{
		new = ft_lstnew("", 1);
		if (!new)
			return (NULL);
		new->content_size = (size_t)fd;
		ft_lstadd(head, new);
		return (*head);
	}
	return (current);
}

static int		truncate_line(char **line, char **content)
{
	size_t			len;
	size_t			str_len;
	char			*tmp;

	len = 0;
	str_len = ft_strlen(*content);
	tmp = ft_strnew(0);
	while ((*content)[len] != '\n' && (*content)[len] != '\0')
		len++;
	if ((*content)[len] == '\n')
		(*content)[len] = '\0';
	*line = ft_strdup(*content);
	if (str_len > len + 1)
	{
		free(tmp);
		tmp = ft_strsub(*content, len + 1, str_len - len);
	}
	ft_strdel(content);
	if (!tmp || !*line)
		return (-1);
	*content = tmp;
	return (1);
}

static int		read_list(char **line, char **content)
{
	if (ft_strchr(*content, '\n') == NULL)
		return (0);
	return (truncate_line(line, content));
}

static int		read_file(int fd, char **line, char **content, char *buff)
{
	char			*buff_tmp;
	int				n_read;

	while (!ft_strchr(buff, '\n'))
	{
		n_read = (int)read(fd, buff, BUFF_SIZE);
		buff[n_read] = '\0';
		if (n_read <= 0)
			break ;
		buff_tmp = *content;
		*content = ft_strjoin(*content, buff);
		if (!*content)
			return (-1);
		free(buff_tmp);
	}
	if (n_read <= 0 && ft_strlen(*content))
	{
		*line = ft_strdup(*content);
		ft_strdel(content);
		return (*line ? 1 : -1);
	}
	else if (ft_strchr(*content, '\n'))
		return (truncate_line(line, content));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*current;
	char			**str;
	char			*buff;
	int				result;

	result = 0;
	buff = ft_strnew(BUFF_SIZE);
	current = find_fd(fd, &head);
	if (fd < 0 || !line || !buff || BUFF_SIZE < 1 || read(fd, buff, 0) ||
	!current)
		return (-1);
	*line = NULL;
	str = (char **)&current->content;
	result = read_list(line, str);
	if (result == 0)
		result = read_file(fd, line, str, buff);
	free(buff);
	return (result);
}
