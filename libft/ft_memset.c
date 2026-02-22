/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:23:18 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/28 15:07:33 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Sets size positions in pointer to the character of value
void	*ft_memset(void *pointer, int value, int size)
{
	char	*ptr;
	int		i;

	ptr = pointer;
	i = 0;
	while (i < size)
	{
		ptr[i] = (char)value;
		i++;
	}
	return (pointer);
}
