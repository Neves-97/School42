/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roda-min <roda-min@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:52:36 by hcorrea-          #+#    #+#             */
/*   Updated: 2024/04/08 15:17:26 by roda-min         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*cont;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		cont = ft_lstnew(f(lst->content));
		if (!cont)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, cont);
		lst = lst->next;
	}
	return (result);
}
