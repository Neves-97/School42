/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:37:04 by roda-min          #+#    #+#             */
/*   Updated: 2023/03/31 13:47:28 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/ft_printf.h"

// %s Prints a string (as defined by the common C convention).

int	ft_printf_s(char *str)
{
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
