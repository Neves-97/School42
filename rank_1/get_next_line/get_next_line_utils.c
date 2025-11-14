/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:15:43 by roda-min          #+#    #+#             */
/*   Updated: 2022/12/16 19:03:48 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] && s[i] != '\n')
		i++;
	if (s && s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (0);
	i = 0;
	while (s1 && s1[i] && s1[i] != '\n')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		new[i++] = s2[j++];
	if (s2[j] == '\n')
		new[i++] = s2[j];
	new[i] = '\0';
	if (s1)
		free(s1);
	return (new);
}
