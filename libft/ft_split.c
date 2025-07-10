/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:28:16 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/10 13:17:08 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_find_total_tokens(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

static char	**ft_memory_allocation(const char *s, char c)
{
	char	**ret;

	ret = malloc(sizeof(char *) * (ft_find_total_tokens(s, c) + 1));
	if (!ret)
	{
		free(ret);
		ret = NULL;
	}
	return (ret);
}

static char	**ft_free_memory(char **ret)
{
	int	j;

	j = 0;
	while (ret[j])
	{
		free(ret[j]);
		j++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	i = 0;
	ret = ft_memory_allocation(s, c);
	while (*s && ret)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i] = ft_substr(s - len, 0, len);
			if (!ret[i])
				ret = ft_free_memory(ret);
			i++;
		}
		else
			++s;
	}
	if (ret != NULL)
		ret[i] = NULL;
	return (ret);
}
