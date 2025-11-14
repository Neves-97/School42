/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:37:18 by roda-min          #+#    #+#             */
/*   Updated: 2022/12/27 14:04:52 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

char			*ft_strchr(const char *s, int c);
unsigned int	ft_strlen(const char *s);
int				ft_putnbr_n(unsigned long int nb, const char *base);

int				ft_printf_c(char c);
int				ft_printf_di(int nb);
int				ft_printf_p(unsigned long int c);
int				ft_printf_s(char *str);
int				ft_printf_u(unsigned int nb);
int				ft_printf_x(unsigned int c);
int				ft_printf_xx(unsigned int c);

int				ft_printf(const char *str, ...);
void			*ft_flags(char c);

#endif
