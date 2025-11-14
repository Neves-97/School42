/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:07 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/02 13:09:37 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	get_size_itoa(int num)
{
	int		size;

	size = 0;
	if (num < 0)
	{
		num = num * -1;
		size++;
	}
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

int	negative(int n, char *str)
{
	str[0] = '-';
	return (n * -1);
}

char	*ft_itoa(int nb)
{
	char	*result;
	int		i;

	i = get_size_itoa(nb);
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nb == 0)
		return (ft_strdup("0"));
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	if (nb < 0)
		nb = negative(nb, result);
	result[i--] = '\0';
	while (nb > 0)
	{
		result[i] = 48 + (nb % 10);
		nb = nb / 10;
		i--;
	}
	return (result);
}

/*int	main()
{
	int num = -2147483648;
	char *result = ft_itoa(num);
	printf("Numero em string: %s", result);
}*/
