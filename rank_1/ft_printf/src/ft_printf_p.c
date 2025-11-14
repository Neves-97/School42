/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:37:00 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:26 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// %p The void * pointer argument has to be printed in hexadecimal format.

int	ft_printf_p(unsigned long int c)
{
	int	n;

	n = 0;
	if (!c)
	{
		n += write (1, "(nil)", 5);
		return (n);
	}
	ft_printf_c('0');
	ft_printf_c('x');
	return (ft_putnbr_n(c, "0123456789abcdef") + 2);
}
