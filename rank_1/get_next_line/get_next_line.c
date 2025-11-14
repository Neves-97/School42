/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:15:40 by roda-min          #+#    #+#             */
/*   Updated: 2022/12/16 19:08:18 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			buf;

	if (fd > FOPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_strjoin(0, buffer);
	if (new_line_buffer(buffer))
		return (line);
	buf = 1;
	while (buf > 0)
	{
		buf = read(fd, buffer, BUFFER_SIZE);
		if ((buf < 0) || (buf == 0 && line[0] == '\0'))
		{
			free(line);
			return (0);
		}
		line = ft_strjoin(line, buffer);
		if (new_line_buffer(buffer))
			break ;
	}
	return (line);
}

int main()
{
	int fd;
	char *line;
	int i = 0;
	fd = open("big_line_no_nl", O_RDONLY);
	while (i < 1)
	{
	line = get_next_line (fd);
	printf("%s" , line);
	i++;
	}
}