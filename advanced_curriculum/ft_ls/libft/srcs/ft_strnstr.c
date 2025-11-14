/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:14 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/22 14:52:20 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	unsigned int	i;
	unsigned int	pos;

	if (!*find)
	{
		return ((char *)str);
	}
	pos = 0;
	while (str[pos] && (size_t)pos < len)
	{
		if (str[pos] == find[0])
		{
			i = 1;
			while (find[i] && str[pos + i] == find[i]
				&& (size_t)(pos + i) < len)
				++i;
			if (find[i] == '\0')
				return ((char *)&str[pos]);
		}
		++pos;
	}
	return (0);
}