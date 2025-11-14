/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:41:04 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/22 14:52:59 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	unsigned int		i;
	unsigned char		*dst;
	unsigned const char	*str;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = 0;
	dst = (unsigned char *)str1;
	str = (unsigned char *)str2;
	while (i < n)
	{
		*((char *)dst + i) = *((char *)str + i);
		i++;
	}
	return (dst);
}
