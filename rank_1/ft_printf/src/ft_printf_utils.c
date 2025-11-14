/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:37:09 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:38 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (unsigned char)c != *s)
		s++;
	if ((unsigned char)c == *s)
		return ((char *)s);
	return (0);
}

unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putnbr_n(unsigned long int nb, const char *base)
{
	int	n;

	n = 0;
	if (nb >= (unsigned long int)ft_strlen(base))
		n += ft_putnbr_n(nb / ft_strlen(base), base);
	n += write(1, &base[nb % ft_strlen(base)], 1);
	return (n);
}
