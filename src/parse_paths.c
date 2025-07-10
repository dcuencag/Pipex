/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:16:11 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/10 16:31:57 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/**
 * @brief Gets the PATH environment variable from the given environment variables.
 *
 * @param envp The environment variables.
 * @return The PATH environment variable, or NULL if not found.
 */
char	*get_env_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

/**
 * @brief Joins a directory path with a command.
 *
 * @param dir The directory path.
 * @param cmd The command to join.
 * @return The joined path, or NULL if any allocation fails.
 */
char	*join_path_cmd(char *dir, char *cmd)
{
	char	*temp;
	char	*full_path;

	if (!dir || !cmd)
		return (NULL);
	temp = ft_strjoin(dir, "/");
	if (!temp)
		return (NULL);
	full_path = ft_strjoin(temp, cmd);
	free(temp);
	return (full_path);
}

/**
 * @brief Finds the path of a command in the given paths.
 *
 * @param paths The paths to search.
 * @param cmd The command to find.
 * @return The path of the command, or NULL if not found.
 */
char	*find_command_path(char **paths, char *cmd)
{
	int		j;
	char	*full_path;

	j = 0;
	while (paths[j])
	{
		full_path = join_path_cmd(paths[j], cmd);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		j++;
	}
	return (NULL);
}

/**
 * @brief Resolves command paths for the pipex program.
 *
 * @param pipex Pointer to the pipex struct.
 * @param paths The paths to resolve.
 */
void	resolve_command_paths(t_pipex *pipex, char **paths)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_count)
	{
		if (!pipex->cmd_args[i][0] || pipex->cmd_args[i][0][0] == '\0')
			pipex->cmd_paths[i] = NULL;
		else if (access(pipex->cmd_args[i][0], X_OK) == 0)
			pipex->cmd_paths[i] = ft_strdup(pipex->cmd_args[i][0]);
		else
			pipex->cmd_paths[i] = find_command_path(paths,
					pipex->cmd_args[i][0]);
		i++;
	}
	pipex->cmd_paths[i] = NULL;
}

void	parse_paths(t_pipex *pipex, char **envp)
{
	char	*path_env;
	char	**paths;
	int		i;

	path_env = get_env_path(envp);
	if (!path_env)
		handle_error("Error: PATH not found");
	paths = ft_split(path_env, ':');
	if (!paths)
		handle_error("Error: Failed to split PATH");
	pipex->cmd_paths = malloc(sizeof(char *) * (pipex->cmd_count + 1));
	if (!pipex->cmd_paths)
		handle_error("Error: Memory allocation failed for cmd_paths");
	resolve_command_paths(pipex, paths);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}
