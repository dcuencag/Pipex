/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 11:07:36 by dancuenc          #+#    #+#             */
/*   Updated: 2025/02/04 12:39:32 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Looks for the firsst appearence of c in *s for n times
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	byte;
	unsigned char	*str;
	size_t			i;

	byte = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == byte)
		{
			return ((void *)(str + i));
		}
		i++;
	}
	return (NULL);
}
