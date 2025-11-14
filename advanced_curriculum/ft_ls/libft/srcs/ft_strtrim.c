/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:42:19 by roda-min          #+#    #+#             */
/*   Updated: 2022/11/08 14:47:55 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string

#include "libft.h"

char	*ft_strtrim(char const	*s1, char const	*set)
{
	size_t	front;
	size_t	rear;
	char	*str;

	str = 0;
	if (!(s1) || !(set))
		return (NULL);
	if (s1 != 0 && set != 0)
	{
		front = 0;
		rear = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (s1[rear - 1] && ft_strchr(set, s1[rear - 1]) && rear > front)
			rear--;
		str = (char *)malloc(sizeof(char) * (rear - front + 1));
		if (str)
			ft_strlcpy(str, &s1[front], rear - front + 1);
	}
	return (str);
}
