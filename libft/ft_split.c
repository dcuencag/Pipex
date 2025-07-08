/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:28:16 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/07 13:22:21 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// Nueva función para comprobar si un carácter es espacio en blanco
static int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f');
}

//Counts the number of words in the string received as an argument.
int	word_counter(const char *s)
{
	int	count;
	int	in_substring;

	count = 0;
	in_substring = 0;
	while (*s)
	{
		if (!is_whitespace(*s) && in_substring == 0)
		{
			in_substring = 1;
			count++;
		}
		else if (is_whitespace(*s))
			in_substring = 0;
		s++;
	}
	return (count);
}

//Creates a word from the string received as an argument.
char	*word_creator(const char **s)
{
	const char	*start;
	char		*word;
	size_t		len;

	while (is_whitespace(**s))
		(*s)++;
	start = *s;
	while (**s && !is_whitespace(**s))
		(*s)++;
	len = *s - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	return (word);
}

//Frees all the memory allocated for the strings.
void	free_all(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

/* Splits the string received as an argument
into words with any whitespace as a delimiter. */
char	**ft_split(char const *s)
{
	char	**str;
	int		ptr_counter;

	if (!s)
		return (NULL);
	str = malloc(sizeof(char *) * (word_counter(s) + 1));
	if (!str)
		return (NULL);
	ptr_counter = 0;
	while (*s != '\0')
	{
		str[ptr_counter] = word_creator(&s);
		if (!str[ptr_counter])
		{
			free_all(str, ptr_counter);
			return (NULL);
		}
		if (str[ptr_counter][0] == '\0')
			free(str[ptr_counter]);
		else
			ptr_counter++;
	}
	str[ptr_counter] = NULL;
	return (str);
}
