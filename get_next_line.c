/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 12:17:22 by ybohusev          #+#    #+#             */
/*   Updated: 2018/01/18 12:17:27 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		copy_to_line(char **line, char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	*line = (char*)ft_memalloc((size_t)i + 1);
	*line = ft_strncpy(*line, file, (size_t)i);
	return (i);
}

static	int		read_from_file(char **file, int fd)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = *file;
		*file = ft_strjoin(*file, buf);
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

static	t_list	*get_current_file(t_list **file, int fd)
{
	t_list	*tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", (size_t)fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

extern	int		get_next_line(const int fd, char **line)
{
	int				read_bytes;
	static	t_list	*files_fd;
	t_list			*curr_file;
	int				copied_bytes;
	char			*tmp;

	if (fd < 0 || !line || read(fd, 0, 0) < 0)
		return (-1);
	curr_file = get_current_file(&files_fd, fd);
	read_bytes = read_from_file((char**)&curr_file->content,
								curr_file->content_size);
	if (read_bytes < BUFF_SIZE && !ft_strlen(curr_file->content))
		return (0);
	copied_bytes = copy_to_line(line, curr_file->content);
	if ((size_t)copied_bytes < ft_strlen(curr_file->content))
	{
		tmp = ft_strsub(curr_file->content, copied_bytes + 1,
						ft_strlen(curr_file->content));
		free(curr_file->content);
		curr_file->content = tmp;
	}
	else
		ft_strclr(curr_file->content);
	return (1);
}
