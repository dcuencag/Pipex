/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:56:18 by dancuenc          #+#    #+#             */
/*   Updated: 2025/03/28 16:11:11 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Search for c in the string *s and return a pointer to the first occurence of c
//If it's c is not found it returns NULL
//If c == '\0' returns a pointer to the terminator of *s
char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (!str || (ft_strlen(str) == 1 && str[0] == '\0'))
		return (NULL);
	if (c == '\0')
		return (str);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
