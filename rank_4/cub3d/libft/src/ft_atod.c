/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:21:44 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/06/30 10:37:38 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

double	parse_integer_part(const char **str)
{
	double	nb;

	nb = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		nb = nb * 10 + (**str - '0');
		(*str)++;
	}
	return (nb);
}

double	parse_float_part(const char **str)
{
	double	part;
	double	divider;

	part = 0.0;
	divider = 10.0;
	while (**str >= '0' && **str <= '9')
	{
		part += (**str - '0') / divider;
		divider *= 10.0;
		(*str)++;
	}
	return (part);
}

double	ft_atod(const char *str)
{
	double	nb;
	double	sign;

	nb = 0.0;
	sign = 1.0;
	while (ft_iswhite(*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	nb = parse_integer_part(&str);
	if (*str == '.' || *str == ',')
	{
		str++;
		nb += parse_float_part(&str);
	}
	return (nb * sign);
}
