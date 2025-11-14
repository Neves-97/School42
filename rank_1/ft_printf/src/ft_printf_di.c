/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:36:49 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:23 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// %d Prints a decimal (base 10) number.
// %i Prints an integer in base 10.

int	ft_printf_di(int nb)
{
	int	n;

	n = 0;
	if (nb == -2147483648)
	{
	n += ft_printf_c('-');
	n += ft_printf_c('2');
	nb = 147483648;
	}
	if (nb < 0)
	{
		nb *= -1;
		n += ft_printf_c('-');
	}
	if (nb > 9)
	{
		n += ft_printf_di(nb / 10);
		n += ft_printf_di(nb % 10);
		return (n);
	}
	else
		n += ft_printf_c(nb + '0');
	return (n);
}
