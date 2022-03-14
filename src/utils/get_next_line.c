/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crendeha <crendeha@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 11:27:41 by crendeha          #+#    #+#             */
/*   Updated: 2021/12/09 16:51:06 by crendeha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

static	char	*get_res(char **line)
{
	char	*res;
	int		len;

	len = 0;
	while ((*line)[len] != '\0' && (*line)[len] != '\n')
		len++;
	if ((*line)[len] == '\n')
		res = malloc(len + 2);
	else
		res = malloc(len + 1);
	if (res == NULL)
	{
		free(*line);
		return (NULL);
	}
	len = 0;
	while ((*line)[len] != '\0' && (*line)[len] != '\n')
	{
		res[len] = (*line)[len];
		len++;
	}
	if ((*line)[len] == '\n')
		res[len++] = '\n';
	res[len] = '\0';
	return (res);
}

static int	process_buffer(char **line)
{
	int		i;
	int		j;
	char	*line_cpy;	

	i = 0;
	while ((*line)[i] != '\0' && (*line)[i] != '\n')
		i++;
	if ((*line)[i++] == '\0')
	{
		free(*line);
		*line = NULL;
	}
	else
	{
		line_cpy = malloc(ft_strlen((*line)) - i + 1);
		if (line_cpy == NULL)
			return (-1);
		j = 0;
		while ((*line)[i] != '\0')
			line_cpy[j++] = (*line)[i++];
		line_cpy[j] = '\0';
		free(*line);
		*line = line_cpy;
	}
	return (1);
}

static char	*output(char **line, int sz)
{
	int		buf;
	char	*res;

	res = NULL;
	if (sz <= 0 && *line == NULL)
		return (NULL);
	else if (sz <= 0 && (*line)[0] == '\0')
	{
		free(*line);
		return (NULL);
	}
	else
	{
		res = get_res(line);
		buf = process_buffer(line);
		if (buf == -1)
		{
			free(*line);
			if (res != NULL)
				free(res);
			return (NULL);
		}
		return (res);
	}
	return (res);
}

static char	*get_line(int fd, char *buf)
{
	static char	*line;
	char		*new_line;
	int			sz;

	sz = read(fd, buf, BUFFER_SIZE);
	while (sz > 0)
	{
		buf[sz] = '\0';
		if (line == NULL)
			line = ft_strdup(buf);
		else
		{
			new_line = ft_strjoin(line, buf);
			free(line);
			line = new_line;
		}
		if (ft_strchr(line, '\n') != NULL)
			break ;
		sz = read(fd, buf, BUFFER_SIZE);
	}
	return (output(&line, sz));
}

char	*ft_get_next_line(int fd)
{
	char	*res;
	char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	res = get_line(fd, buf);
	free(buf);
	return (res);
}
