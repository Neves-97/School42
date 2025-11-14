/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 09:51:18 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/02 13:10:16 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (!(s1 || s2))
		return (NULL);
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	j = 0;
	while (s1[i])
	{
		result[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}
