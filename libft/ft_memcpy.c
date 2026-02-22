/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:22:45 by dancuenc          #+#    #+#             */
/*   Updated: 2025/02/04 12:41:51 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Copies the n bytes from one string to an other
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destiny;
	unsigned const char	*source;
	size_t				i;

	destiny = (unsigned char *)dest;
	source = (unsigned char *)src;
	if (destiny == source || n <= 0)
	{
		return (dest);
	}
	i = 0;
	while (i < n)
	{
		destiny[i] = source[i];
		i++;
	}
	return (dest);
}
