/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:43:18 by dancuenc          #+#    #+#             */
/*   Updated: 2025/02/04 13:33:52 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Function to be applied to each element of the list
/* void print_element(void *content)
{
	printf("%s\n", (char *)content);
} */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*aux;

	if (!lst || !f)
		return ;
	aux = lst;
	while (aux)
	{
		f(aux->content);
		aux = aux->next;
	}
}
