/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:40:11 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/03/16 16:18:17 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int	nbr;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = (int)(nb * -1);
	}
	else
		nbr = (int)nb;
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((char)(nbr % 10 + 48), fd);
}

/*int main()
{
	FILE	*file = fopen("test.txt", "w");
	int		fd = fileno(file);

	ft_putnbr_fd(153, fd);
	fclose(file);
	return 0;
}*/