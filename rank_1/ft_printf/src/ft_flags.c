/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:21:33 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:46:57 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// manage flags

void	*ft_flags(char c)
{
	if (c == 'c')
		return (&ft_printf_c);
	if (c == 's')
		return (&ft_printf_s);
	if (c == 'd')
		return (&ft_printf_di);
	if (c == 'i')
		return (&ft_printf_di);
	if (c == 'p')
		return (&ft_printf_p);
	if (c == 'u')
		return (&ft_printf_u);
	if (c == 'x')
		return (&ft_printf_x);
	if (c == 'X')
		return (&ft_printf_xx);
	else
		return (0);
}
