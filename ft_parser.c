#include "pipex.h"

int	path_checker(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			return (i);
		i++;
	}
	ft_error();
	return(i);
}

static char	*path_getter(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*path;
	char	*cmd_path;

	i = path_checker(env);
	env_paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/");
		cmd_path = ft_strjoin(path, cmd);
		free(path);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_security(env_paths, i);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_security(env_paths);
	ft_error();
	return (EXIT_SUCCESS);
}

