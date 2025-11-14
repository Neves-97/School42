/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:40:55 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/26 17:02:27 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = lenght(n);
	res = (char *)(i + 1 * sizeof(char));
	if (!res)
		return (0);
	res[i] = '\0';
	i--;
	if (n == 0)
		res[0] = '0';
	else if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (res);
}

// int main(void)
// {
// 	printf("%s\n", ft_itoa(123156));
// 	return (0);
// }
