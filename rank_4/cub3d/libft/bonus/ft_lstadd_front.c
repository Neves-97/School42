/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcorrea- <hcorrea-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:49:35 by hcorrea-          #+#    #+#             */
/*   Updated: 2023/01/13 10:26:30 by hcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}

/*int main()
{
	t_list **lista_de_listas;
	
	int number1 = 1;
	t_list *struc = ft_lstnew(&number1);
	lista_de_listas = &struc;

	int number2 = 2;
	t_list *struc2 = ft_lstnew(&number2);
	
	ft_lstadd_front(lista_de_listas, struc2);

	int number3 = 3;
	t_list *struc3 = ft_lstnew(&number3);
	
	ft_lstadd_front(lista_de_listas, struc3);

	int number4 = 4;
	t_list *struc4 = ft_lstnew(&number4);
	
	ft_lstadd_front(lista_de_listas, struc4);
	
	printf("Primeiro elemento da lista de listas: %i\n",
	*(int*)(*lista_de_listas)->content);
	printf("Segundo elemento da lista de listas: %i\n",
	*(int*)(*lista_de_listas)->next->content);
	printf("Terceiro elemento da lista de listas: %i\n",
	*(int*)(*lista_de_listas)->next->next->content);
	printf("Quarto elemento da lista de listas: %i",
	*(int*)(*lista_de_listas)->next->next->next->content);
}*/
