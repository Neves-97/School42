/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:22 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/26 17:04:09 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (0);
		*sub = '\0';
		return (sub);
	}
	if (s_len < len)
		return (ft_strdup((char *)s + start));
	i = 0;
	sub = (char *)malloc(len + 1 * sizeof(char));
	if (!sub)
		return (0);
	while (start < s_len && i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}
