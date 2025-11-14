/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:07:05 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/16 16:15:49 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memchr(const void *str, int c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (0);
}
