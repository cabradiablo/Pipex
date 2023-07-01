#include "pipex.h"

void	child_input(int *fd, char **argv, char **env)
{
	pid_t	child;
	int		fd_input;

	child = fork();
	if (child < 0)
		ft_error();
	if (child == 0)
	{
		fd_input = open(argv[1], O_RDONLY);
		if (fd_input < 0)
			ft_error();
		close(fd[0]);
		dup2(fd_input, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		ft_exec(argv[2], env);
	}
}

void	child_middle(int **fd, int pos, char **argv, char **env)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		ft_error();
	if (child == 0)
	{
		dup2(fd[0][1], STDIN_FILENO);
		dup2(fd[1][0], STDOUT_FILENO);
        close(fd[0][0]);
		ft_exec(argv[pos], env);
	}
}

void	child_output(int *fd, int pos, char **argv, char **env)
{
	pid_t	child;
	int		fd_output;

	child = fork();
	if (child < 0)
		ft_error();
	if (child == 0)
	{
		fd_output = open(argv[pos + 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (fd_output < 0)
			ft_error(argv[pos + 1]);
		dup2(fd_output, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
        close(fd[1]);
		ft_exec(argv[pos], env);
	}
}