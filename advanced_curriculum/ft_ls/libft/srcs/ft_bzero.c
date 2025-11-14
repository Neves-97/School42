/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:39:03 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/08 16:01:40 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*str;

	if (n == 0)
		return ;
	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

// int	main()
// {
// 	char str[50] = "This is string.h library function";
// 	ft_bzero(str, 50);
// 	puts(str);
// 	return (0);
// }
