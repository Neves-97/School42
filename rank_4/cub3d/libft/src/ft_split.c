/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:46:42 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/02 13:09:56 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_words(char *str, char c)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (*str)
	{
		if (*str != c && total == 0)
		{
			total = 1;
			i++;
		}
		else if (*str == c)
			total = 0;
		str++;
	}
	return (i);
}

char	*get_word(char *str, int start, int end)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result || !str)
		return (NULL);
	while (start < end)
	{
		result[i] = str[start];
		start++;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		index;
	int		i;
	int		j;

	result = (char **)malloc(sizeof(char *)
			* (count_words((char *)str, c) + 1));
	if (!str || !result)
		return (NULL);
	index = -1;
	i = 0;
	j = 0;
	while (i <= ft_strlen2(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen2(str)) && index >= 0)
		{
			result[j++] = get_word((char *)str, index, i);
			index = -1;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}
