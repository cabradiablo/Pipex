#include "pipex.h"

void	pipex(char **argv, char **env)
{
	int	fd[2];
	int	pos;

	if (pipe(fd) < 0)
		ft_error(NULL);
	child_input(fd, argv, env);
	child_output(fd, argv, env, 3);
	close(fd[0]);
	close(fd[1]);
	waitpid(0, &pos, 0);
	waitpid(0, &pos, 0);
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int	fd[1][2];
	int	pos;

	pos = 1
	if (pipe(fd[0]) < 0 || pipe(fd[1]) < 0)
		ft_error();
	child_input(fd[0], argv, env);
	while (argc > ++pos)
		child_middle(fd, pos, argv, env);
	child_output(fd[pos], argv, env, argc - 2);
	close(fd[0][0]);
	close(fd[0][1]);
	while (pos-- > 1)
		waitpid(0, &pos, 0);
}
