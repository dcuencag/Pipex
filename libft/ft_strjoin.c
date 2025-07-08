/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:20:01 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/07 11:08:06 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <strings.h>

//Reserves space for a new string where *s1 + *s2 will be stored
//If it fails it returns NULL
//If it succeds it returns the new string with s1 + s2 in it
char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;
	int		total;

	total = ft_strlen(stash) + ft_strlen(buffer);
	str = ft_calloc(sizeof(char), (total + 1));
	if (!str || !stash || !buffer)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		str[i] = buffer[j];
		i++;
		j++;
	}
	if (stash)
		free(stash);
	return (str);
}
