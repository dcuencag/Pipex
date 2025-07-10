#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include "libft/libft.h"
#include <string.h>
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

void		init_files(char **argv, int argc, t_pipex *pipex);
void		get_infile(char **argv, t_pipex *pipex);
void		get_outfile(char *argv, t_pipex *pipex);
void		create_pipes(t_pipex *pipex);
void		close_pipes(t_pipex *pipex);

void		redirect_io(int input_fd, int output_fd);
void		setup_child_io(t_pipex *pipex);
void		handle_child_error(t_pipex *pipex, int saved_stdout);
void		execute_child_command(t_pipex *pipex, char **envp);
void		create_child_process(t_pipex *pipex, char **envp);

int			check_and_set_heredoc(char *arg, t_pipex *pipex);
int			create_heredoc_file(void);
void		process_heredoc_input(char *limiter, int fd);
void		finalize_heredoc(t_pipex *pipex);
void		handle_heredoc(char *limiter, t_pipex *pipex);

void		parse_cmds(t_pipex *pipex, char **argv);
void		parse_paths(t_pipex *pipex, char **envp);
void		create_child_process(t_pipex *pipex, char **envp);

void		safe_close(int *fd);
void		cleanup_heredoc(t_pipex *pipex);
void		free_cmd_paths(t_pipex *pipex);
void		free_cmd_args(t_pipex *pipex);
void		parent_free(t_pipex *pipex);

void		handle_error(const char *message);
int			handle_msg(char *err);


#endif