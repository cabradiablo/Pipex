#include "pipex.h"



void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, SPACE);
	if (!cmd)
	{
		ft_security(cmd);
		ft_error();
	}
	path = path_getter(cmd[0], env);
	if (execve(path, cmd, env) == -1)
		ft_error();
}
void	ft_error(void)
{
	exit(0);
}
