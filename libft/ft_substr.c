/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:30:06 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/10 13:17:19 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

//Extracts a substring from the given string s
//The substring starts at index 'start' and spans up to 'len' characters
//If 'start' is greater than the length of s, returns an empty string
//Allocates memory for the substring and ensures it is NULL-terminated
//Returns the newly allocated substring, or NULL if allocation fails
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	else
	{
		ft_memcpy(result, s + start, len);
		result[len] = '\0';
	}
	return (result);
}
