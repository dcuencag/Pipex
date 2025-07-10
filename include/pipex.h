/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dancuenc <dancuenc@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 13:15:07 by dancuenc          #+#    #+#             */
/*   Updated: 2025/07/10 16:30:24 by dancuenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include "libft/libft.h"
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_ENVP "Environment"
# define ERR_CMD "Command not found: "
# define ERR_HEREDOC "here_doc"

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		here_doc;
	int		is_invalid_infile;
	char	**cmd_paths;
	char	***cmd_args;
	int		cmd_count;
	int		pipe_count;
	int		*pipes;
	int		idx;
	pid_t	pid;
}			t_pipex;

/**
 * @brief Entry point for the pipex program.
 *
 * Parses arguments, sets up the pipeline, executes commands, and handles cleanup.
 *
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param envp Environment variables.
 * @return 0 on success, error code otherwise.
 */
int			main(int ac, char **av, char **envp);

/**
 * @brief Initializes the files for the pipex program.
 *
 * @param argv Argument vector.
 * @param argc Argument count.
 */
void		init_files(char **argv, int argc, t_pipex *pipex);

/**
 * @brief Gets the input file for the pipex program.
 *
 * @param argv Argument vector.
 * @param pipex Pointer to the pipex struct.
*/
void		get_infile(char **argv, t_pipex *pipex);

/**
 * @brief Gets the output file for the pipex program.
 *
 * @param argv Argument vector.
 * @param pipex Pointer to the pipex struct.
*/
void		get_outfile(char *argv, t_pipex *pipex);

/**
 * @brief Creates pipes for the pipex program.
 *
 * @param pipex Pointer to the pipex struct.
*/
void		create_pipes(t_pipex *pipex);

/**
 * @brief Closes pipes for the pipex program.
 *
 * @param pipex Pointer to the pipex struct.
*/
void		close_pipes(t_pipex *pipex);

/**
 * @brief Redirects input and output file descriptors.
 *
 * @param input_fd Input file descriptor.
 * @param output_fd Output file descriptor.
*/
void		redirect_io(int input_fd, int output_fd);

/**
 * @brief Sets up child process input and output file descriptors.
 *
 * @param pipex Pointer to the pipex struct.
*/
void		setup_child_io(t_pipex *pipex);

/**
 * @brief Handles errors for child processes.
 *
 * @param pipex Pointer to the pipex struct.
 * @param saved_stdout Saved standard output file descriptor.
*/
void		handle_child_error(t_pipex *pipex, int saved_stdout);

/**
 * @brief Executes a child command.
 *
 * @param pipex Pointer to the pipex struct.
 * @param envp Environment variables.
*/
void		execute_child_command(t_pipex *pipex, char **envp);

/**
 * @brief Creates a child process.
 *
 * @param pipex Pointer to the pipex struct.
 * @param envp Environment variables.
*/
void		create_child_process(t_pipex *pipex, char **envp);

/**
 * @brief Checks if the argument is a heredoc and sets the heredoc flag.
 *
 * @param arg Argument string.
 * @param pipex Pointer to the pipex struct.
*/
int			check_and_set_heredoc(char *arg, t_pipex *pipex);

/**
 * @brief Creates a heredoc file.
 *
 * @return The file descriptor of the created file.
*/
int			create_heredoc_file(void);

/**
 * @brief Processes input for a heredoc.
 *
 * @param limiter The limiter string.
 * @param fd The file descriptor to write to.
*/
void		process_heredoc_input(char *limiter, int fd);

/**
 * @brief Handles a heredoc.
 *
 * @param limiter The limiter string.
 * @param pipex Pointer to the pipex struct.
*/
void		handle_heredoc(char *limiter, t_pipex *pipex);

/**
 * @brief Parses commands for the pipex program.
 *
 * @param pipex Pointer to the pipex struct.
 * @param argv Argument vector.
*/
void		parse_cmds(t_pipex *pipex, char **argv);

/**
 * @brief Parses paths for the pipex program.
 *
 * @param pipex Pointer to the pipex struct.
 * @param envp Environment variables.
*/
void		parse_paths(t_pipex *pipex, char **envp);

/**
 * @brief Safely closes a file descriptor and sets it to -1.
 *
 * @param fd Pointer to the file descriptor to close.
 */
void		safe_close(int *fd);

/**
 * @brief Removes the heredoc temporary file if here_doc mode is active.
 *
 * @param pipex Pointer to the pipex struct.
 */
void		cleanup_heredoc(t_pipex *pipex);

/**
 * @brief Frees memory allocated for command paths in the pipex struct.
 *
 * @param pipex Pointer to the pipex struct.
 */
void		free_cmd_paths(t_pipex *pipex);

/**
 * @brief Frees memory allocated for command arguments in the pipex struct.
 *
 * @param pipex Pointer to the pipex struct.
 */
void		free_cmd_args(t_pipex *pipex);

/**
 * @brief Frees all resources allocated in the pipex struct and closes file descriptors.
 *
 * @param pipex Pointer to the pipex struct.
 */
void		parent_free(t_pipex *pipex);

/**
 * @brief Prints an error message using perror.
 *
 * @param message The error message to print.
 */
void		handle_error(const char *message);

/**
 * @brief Prints a generic error message to stderr and returns 1.
 *
 * @param err The error message to print.
 * @return Always returns 1.
 */
int			handle_msg(char *err);

#endif