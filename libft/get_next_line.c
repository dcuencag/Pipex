/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:42:19 by dancuenc          #+#    #+#             */
/*   Updated: 2025/05/08 15:52:19 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *src)
{
	char	*dst;
	size_t	i;

	dst = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/**
 * Read from a file descriptor until a newline character is found
 * @param fd The file descriptor to read from
 * @param storage The string to store the read data
 * @return A pointer to the stored data, or NULL if an error occurred
 */
char	*read_to_stash(int fd, char *storage)
{
	char	*buff;
	int		bytes_read;

	bytes_read = 1;
	if (!storage)
		storage = ft_calloc(sizeof(char), 1);
	if (!storage)
		return (NULL);
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (free(storage), NULL);
	while (!ft_strchr(buff, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buff), free(storage), NULL);
		buff[bytes_read] = '\0';
		storage = ft_strjoin(storage, buff);
	}
	free(buff);
	return (storage);
}

/**
 * Extract a line from a string
 * @param current_line The string to extract the line from
 * @return A pointer to the extracted line, or NULL if an error occurred
 */
char	*extract_line(char *current_line)
{
	char	*new_line;
	int		i;

	if (!current_line)
		return (NULL);
	if (current_line && (!ft_strchr(current_line, '\n')))
	{
		return (current_line);
	}
	new_line = ft_calloc(sizeof(char), ft_strlen(current_line) + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (current_line[i] != '\n' && current_line[i] != '\0')
	{
		new_line[i] = current_line[i];
		i++;
	}
	if (current_line[i] == '\n')
		new_line[i] = current_line[i];
	new_line[i + 1] = '\0';
	return (new_line);
}

/**
 * Update the stash after a line has been extracted
 * @param stash The string to update
 * @return A pointer to the updated stash
 */
char	*update_stash(char **stash)
{
	char	*line_read;
	char	*tmp;
	char	*ptr;
	char	*line;

	if (!stash)
		return (NULL);
	line_read = extract_line(*stash);
	if (!line_read)
		return (NULL);
	if (!ft_strchr(*stash, '\n'))
	{
		line = *stash;
		*stash = NULL;
		return (line);
	}
	tmp = ft_strchr(*stash, '\n') + 1;
	if (!tmp)
		return (NULL);
	ptr = ft_substr(tmp, 0, ft_strlen(tmp));
	tmp = NULL;
	free(*stash);
	*stash = ptr;
	return (line_read);
}

char	*get_next_line(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_to_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	if (ft_strchr(stash[fd], '\n'))
		return (update_stash(&stash[fd]));
	line = stash[fd];
	stash[fd] = NULL;
	if (line[0] == '\0')
	{
		free(line);
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = NULL;
	return (line);
}
/* 
int main(int ac, char **av)
{
	if (ac < 2)
	{
		printf("Invalid number of arguments.\n");
		return (0);
	}
	if (ac > 7)
	{
		printf("Too many arguments.\n");
		return (0);
	}
	if (BUFFER_SIZE <= 0)
	{
		printf("Invalid buffer size.\n");
		return (0);
	}
	int fd1 = 0;
	int fd2 = 0;
	int fd3 = 0;
	int fd4 = 0;
	int fd5 = 0;
	int fd6 = 0;
	if (ac >= 2)
	{
		fd1 = open(av[1], O_RDONLY);
		if (fd1 < 0)
			fd1 = 0;
	}
	if (ac >= 3)
	{
		fd2 = open(av[2], O_RDONLY);
		if (fd2 < 0)
			fd2 = 0;
	}
	if (ac >= 4)
	{
		fd3 = open(av[3], O_RDONLY);
		if (fd3 < 0)
			fd3 = 0;
	}
	if (ac >= 5)
	{
		fd4 = open(av[4], O_RDONLY);
		if (fd4 < 0)
			fd4 = 0;
	}
	if (ac >= 6)
	{
		fd5 = open(av[5], O_RDONLY);
		if (fd5 < 0)
			fd5 = 0;
	}
	if (ac >= 7)
	{
		fd6 = open(av[6], O_RDONLY);
		if (fd6 < 0)
			fd6 = 0;
	}
		
	char *line;
	while (fd1 != 0 || fd2 != 0 || fd3 != 0 || fd4 != 0 || fd5 != 0 || fd6 != 0)
	{
		line = get_next_line(fd1);
		if (fd1 != 0 && line)
		{
			printf("%s", line);
			free(line);
		}
		else if (fd1 != 0)
		{
			close(fd1);
			fd1 = 0;
		}
		line = get_next_line(fd2);
		if (fd2 != 0 && line)
		{
			printf("%s", line);
			free(line);
		}
		else if (fd2 != 0)
		{
			close(fd2);
			fd2 = 0;
		}
		line = get_next_line(fd3);
		if (fd3 != 0 && line)
		{
			printf("%s", line);
			free(line);
		}
		else if (fd3 != 0)
		{
			close(fd3);
			fd3 = 0;
		}
		line = get_next_line(fd4);
		if (fd4 != 0 && line)
		{
			printf("%s", line);
			free(line);
		}
		else if (fd4 != 0)
		{
			close(fd4);
			fd4 = 0;
		}
		line = get_next_line(fd5);
		if (fd5 != 0 && line)
		{
			printf("%s", line);
			free(line);
		}
		else if (fd5 != 0)
		{
			close(fd5);
			fd5 = 0;
		}
		line = get_next_line(fd6);
		if (fd6 != 0 && line)
		{
			printf("%s", line);
			free(line);
		}
		else if (fd6 != 0)
		{
			close(fd6);
			fd6 = 0;
		}
	}
	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	close(fd5);
	close(fd6);
	return (0);
} */