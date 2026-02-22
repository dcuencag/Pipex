/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:09:48 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:51:39 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Creates a double of the string *s1 reserving memory with malloc
//If it fails in malloc it returns NULL
//If it succeeds it returns a pointer to the new string
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(ft_strlen(s) + 1);
	i = 0;
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
