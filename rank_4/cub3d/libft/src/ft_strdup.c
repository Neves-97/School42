/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:24:06 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/02 13:10:05 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = (char *)malloc(ft_strlen(s1) + 1);
	if (!result || !s1)
		return (NULL);
	ft_memcpy(result, s1, ft_strlen(s1) + 1);
	return (result);
}
