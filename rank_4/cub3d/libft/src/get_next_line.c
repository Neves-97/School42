/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:43:04 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/27 11:29:47 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*static int	nl_index(char *stash)
{
	int	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n' || stash[i] == '\r')
			return (i);
		i++;
	}
	return (0);
}

static char	*cleanup_crew(char **stash)
{
	char	*line;
	char	*temp;
	int		i;

	if (!*stash || **stash == '\0')
		return (NULL);
	i = nl_index(*stash);
	if (ft_strchr(*stash, '\n') || ft_strchr(*stash, '\r'))
	{
		line = ft_substr(*stash, 0, i);
		temp = ft_substr(*stash, i + 1, ft_strlen(*stash) - i - 1);
		free(*stash);
		*stash = temp;
		if (**stash != '\0')
			return (line);
	}
	else
		line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	int			readchard;
	char		*buff;
	char		*temp;
	static char	*stash[FOPEN_MAX];

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	readchard = read(fd, buff, BUFFER_SIZE);
	while (readchard > 0)
	{
		buff[readchard] = '\0';
		if (!stash[fd])
			stash[fd] = ft_strdup("");
		temp = ft_strjoin(stash[fd], buff);
		free(stash[fd]);
		stash[fd] = temp;
		if (ft_strchr(stash[fd], '\n'))
			break ;
		readchard = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (cleanup_crew(&stash[fd]));
}*/

char	*read_line(int fd, int *rd)
{
	char	character;
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc(100000);
	if (buffer == NULL)
		return (NULL);
	while (1)
	{
		*rd = read(fd, &character, 1);
		if (*rd <= 0)
			break ;
		buffer[i++] = character;
		if (character == '\n' || character == '\r' || *rd <= 0)
			break ;
	}
	if (i > 0)
		buffer[i - 1] = '\0';
	else
		buffer[i] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	int		rd;
	char	*buffer;

	buffer = read_line(fd, &rd);
	if (rd == -1 || buffer == NULL || (!buffer[0] && rd <= 0))
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
