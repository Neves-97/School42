/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 16:19:19 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/02 13:05:00 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(int nitems, int size)
{
	int		total_size;
	void	*result;

	total_size = nitems * size;
	result = malloc(total_size);
	if (!result)
		return (NULL);
	ft_memset(result, 0, total_size);
	return (result);
}
