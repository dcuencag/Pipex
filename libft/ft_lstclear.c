/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:39:39 by dancuenc          #+#    #+#             */
/*   Updated: 2025/02/04 18:29:56 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void deleteInt(void *data)
{
	int *ptr = (int *)data;
	printf("Deleting integer: %d\n", *ptr);
	free(ptr);
} */
//Deletes and frees the node and every successor of that node
//Uses ’del’ and free to empty each node
//Finally, the pointer to the list is set to NULL.
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}
