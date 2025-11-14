/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:24:04 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/16 16:16:22 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	int	i;
	int	srcsize;

	if (!src && !dst)
		return (0);
	i = 0;
	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcsize);
}

/*int	main(void)
{
	int 	src_size;
	char 	*src;
	char 	*dest;

	src = calloc(11, sizeof(char));
	dest = calloc(8, sizeof(char));
	src = "alo galera";
	src_size = ft_strlcpy(dest, src, 8);
	printf("src: %s\n", src);
	printf("dest: %s\n", dest);
	printf("src_size: %d\n", src_size);
	return(0);
}*/
