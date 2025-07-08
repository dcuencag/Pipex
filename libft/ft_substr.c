/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:30:06 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/28 16:10:49 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Extracts a substring from the given string s
//The substring starts at index 'start' and spans up to 'len' characters
//If 'start' is greater than the length of s, returns an empty string
//Allocates memory for the substring and ensures it is NULL-terminated
//Returns the newly allocated substring, or NULL if allocation fails
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s || start >= ft_strlen(s))
		return (NULL);
	sub = (char *)ft_calloc(sizeof(char), len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
