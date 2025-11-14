/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:24:14 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/16 16:14:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strlcat(char *dst, const char *src, int dstsize)
{
	int	i;
	int	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (src[j] && i + 1 < dstsize)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
