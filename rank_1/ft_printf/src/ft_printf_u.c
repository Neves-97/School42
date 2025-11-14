/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:37:06 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:30 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// %u Prints an unsigned decimal (base 10) number.

int	ft_printf_u(unsigned int nb)
{
	int	n;

	n = 0;
	if (nb >= 10)
	{
		n += ft_printf_u(nb / 10);
		n += ft_printf_u(nb % 10);
	}
	else
		n += ft_printf_c(nb + '0');
	return (n);
}
