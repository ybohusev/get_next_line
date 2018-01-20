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
#include <stdio.h>

static	int		copy_to_line(char **line, char *file)
{
	int		i;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	*line = (char*)ft_memalloc((size_t)i + 1);
	*line = ft_strncpy(*line, file, (size_t)i);
	ft_strdel(&file);
	return (i);
}

static	int		read_from_file(t_list *file, char buf[BUFF_SIZE + 1])
{
	int		ret;
	void	**tmp;

	while ((ret = read(file->content_size, buf, BUFF_SIZE)))
	{
		tmp = &*file->content;
		buf[ret] = '\0';
		file->content = ft_strjoin(file->content, buf);
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
	free(tmp->content);
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
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	curr_file = get_current_file(&files_fd, fd);
	curr_file->content = ft_strnew(1);
	read_bytes = read_from_file(curr_file, buf);
	if (read_bytes < BUFF_SIZE && !ft_strlen(curr_file->content))
		return (0);
	copied_bytes = copy_to_line(line, curr_file->content);
	if ((size_t)copied_bytes < ft_strlen(curr_file->content))
		curr_file->content += copied_bytes + 1;
	else
		ft_strclr(curr_file->content);
	return (1);
}
