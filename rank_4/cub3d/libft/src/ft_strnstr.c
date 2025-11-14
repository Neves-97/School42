/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:41:44 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/16 16:16:34 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *str, const char *search, int len)
{
	int	i;
	int	j;

	i = 0;
	if (search[0] == '\0')
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		while (str[i] == search[j] && str[i] && i < len)
		{
			i++;
			j++;
		}
		if (!(search[j]))
			return ((char *)&str[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
