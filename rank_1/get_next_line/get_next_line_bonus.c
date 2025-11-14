/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:06:47 by roda-min          #+#    #+#             */
/*   Updated: 2022/12/16 17:29:44 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	new_line_buffer(char *buffer)
{
	int	i;
	int	j;
	int	new_line;

	i = 0;
	j = 0;
	new_line = 0;
	while (buffer[i])
	{
		if (new_line == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			new_line = 1;
		buffer[i] = 0;
		i++;
	}
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			buf;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strjoin(0, buffer[fd]);
	if (new_line_buffer(buffer[fd]))
		return (line);
	buf = 1;
	while (buf > 0)
	{
		buf = read(fd, buffer[fd], BUFFER_SIZE);
		if ((buf == -1) || (buf == 0 && line[0] == '\0'))
		{
			free (line);
			return (0);
		}
		line = ft_strjoin(line, buffer[fd]);
		if (new_line_buffer(buffer[fd]))
			break ;
	}
	return (line);
}
