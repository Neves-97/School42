/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:59:20 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:55 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = (t_list *)malloc(sizeof(t_list));
	if (!result)
		return (NULL);
	result->content = content;
	result->next = NULL;
	return (result);
}

/*int	main()
{
	int number = 1234;
	char *string = "Kasakh";
	t_list *lststr = ft_lstnew(string);
	t_list *lstnbr = ft_lstnew(&number);
	char *str = lststr->content;
	int nbr = *(int *)lstnbr->content;
	printf("Primeiro elemento da lista (String): %s.\n", str);
	printf("Primeiro elemento da lista (Numero): %i.", nbr);
}*/