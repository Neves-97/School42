/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:37:16 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:50 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		n;

	va_start(ap, str);
	n = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("scXxiupd", str[++i]))
			{
				n += ((int (*)())ft_flags(str[i]))(va_arg(ap, void *));
				i++;
			}
			else
				n += write(1, &str[i++], 1);
		}
		else
			n += write(1, &str[i++], 1);
	}
	va_end(ap);
	return (n);
}
