/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:32:49 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/02 13:06:46 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(const char *str, int start, int len)
{
	char	*result;
	int		i;
	int		j;

	i = start;
	j = 0;
	if (!str)
		return (NULL);
	if (start >= ft_strlen(str))
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		*result = '\0';
		return (result);
	}
	if (len > ft_strlen(str))
		return (ft_strdup((char *)str + start));
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (j < len && i < ft_strlen(str))
		result[j++] = str[i++];
	result[j] = '\0';
	return (result);
}
