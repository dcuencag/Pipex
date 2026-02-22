/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:16:00 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/10 17:13:56 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <string.h>

/**
 * @brief Initializes and validates command-line arguments and heredoc mode.
 *
 * Sets all fields of the pipex struct to zero and
 * checks for heredoc mode and argument count.
 *
 * @param ac Argument count.
 * @param av Argument vector.
 * @param pipex Pointer to the pipex struct to initialize.
 * @return 0 on success, 1 on error.
 */
static int	initialize_and_validate(int ac, char **av, t_pipex *pipex)
{
	memset(pipex, 0, sizeof(*pipex));
	if (ac < check_and_set_heredoc(av[1], pipex))
		return (handle_msg(ERR_INPUT));
	return (0);
}

/**
 * @brief Sets up files, parses commands and paths, creates pipes,
 * and executes child processes.
 *
 * @param pipex Pointer to the pipex struct.
 * @param ac Argument count.
 * @param av Argument vector.
 * @param envp Environment variables.
 */
static void	setup_and_execute(t_pipex *pipex, int ac,
	char **av, char **envp)
{
	init_files(av, ac, pipex);
	parse_cmds(pipex, av);
	parse_paths(pipex, envp);
	create_pipes(pipex);
	pipex->idx = -1;
	while (++(pipex->idx) < pipex->cmd_count)
		create_child_process(pipex, envp);
	close_pipes(pipex);
}

/**
 * @brief Waits for all child processes and
 * returns the exit status of the last command.
 *
 * @param pipex Pointer to the pipex struct.
 * @return Exit status of the last executed command.
 */
static int	handle_exit_status(t_pipex *pipex)
{
	int	status;
	int	last_exit_status;
	int	last_exit_id;

	last_exit_status = 0;
	last_exit_id = waitpid(-1, &status, 0);
	while (last_exit_id > 0)
	{
		if (WIFEXITED(status) && pipex->pid == last_exit_id)
			last_exit_status = WEXITSTATUS(status);
		last_exit_id = waitpid(-1, &status, 0);
	}
	return (last_exit_status);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		exit_status;

	if (initialize_and_validate(argc, argv, &pipex))
		return (1);
	setup_and_execute(&pipex, argc, argv, envp);
	exit_status = handle_exit_status(&pipex);
	parent_free(&pipex);
	return (exit_status);
}
