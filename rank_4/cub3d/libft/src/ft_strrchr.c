/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:34:37 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:05 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int			i;
	const char	*pos_ini;

	pos_ini = str;
	i = ft_strlen(str);
	str = (str + i);
	while (str != pos_ini && (unsigned char)c != *str)
		str--;
	if (*str == (unsigned char)c)
		return ((char *)str);
	return (0);
}

/*int	main ()
{
	char *str = "Oi, tudo bem. Eespero que sim.?";
	printf("Ultimo 'o' encontrado: %s", ft_strrchr(str, 'o'));
}*/
