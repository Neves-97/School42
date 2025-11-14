/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:41:32 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/02 10:23:11 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != (char)c && *str)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return (NULL);
}
