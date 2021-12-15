/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjokela <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 14:34:14 by mjokela           #+#    #+#             */
/*   Updated: 2021/12/10 14:34:21 by mjokela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	join_to_line(char **line, char buf[])
{
	char	*temp;

	temp = ft_strjoin(*line, buf);
	free(*line);
	*line = temp;
}

static int	read_buf(char *arr[FD_SIZE], const int fd, char **line, char *tmp)
{
	char	buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	while (read(fd, buf, BUFF_SIZE) > 0)
	{
		tmp = ft_strchr(buf, '\n');
		if (tmp != NULL)
		{
			tmp[0] = '\0';
			join_to_line(line, buf);
			tmp++;
			arr[fd] = ft_strdup(tmp);
			return (1);
		}
		if (*line == NULL)
			*line = ft_strdup(buf);
		else
			join_to_line(line, buf);
		free(tmp);
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (*line == NULL || *line[0] == '\0')
		return (0);
	return (1);
}

static int	check_arr(char *arr[FD_SIZE], int fd, char **line)
{
	char	*tmp;

	tmp = NULL;
	if (arr[fd] == NULL)
		return (read_buf(arr, fd, line, tmp));
	tmp = ft_strchr(arr[fd], '\n');
	if (tmp == NULL)
	{
		*line = ft_strdup(arr[fd]);
		arr[fd][0] = 0;
		return (read_buf(arr, fd, line, tmp));
	}
	tmp[0] = '\0';
	*line = ft_strdup(arr[fd]);
	tmp++;
	arr[fd] = tmp;
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*arr[FD_SIZE];

	if (read(fd, arr[0], 0) < 0)
		return (-1);
	if (fd < 0 || fd > FD_SIZE || !line)
		return (-1);
	*line = NULL;
	return (check_arr(arr, fd, line));
}
