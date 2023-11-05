/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:50 by alepinto          #+#    #+#             */
/*   Updated: 2023/11/05 05:42:29 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (i);
}

char	*path_getter(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*path;
	char	*cmd_path;

	i = path_checker(env);
	if (!env[i])
		return (NULL);
	env_path = ft_split(env[i] + 5, ':');
	i = 0;
	while (env_path[i])
	{
		path = ft_strjoin(env_path[i], "/");
		cmd_path = ft_strjoin(path, cmd);
        if (path)
		    free(path);
		if (access(cmd_path, X_OK) == 0)
		{
			ft_free_matrix(env_path);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	return (ft_free_matrix(env_path), NULL);
}

int	relative_path(char **cmd, char **path)
{
	int	check;
    
    if (*cmd == NULL)
        return (0);
	check = 0;
    if (ft_strncmp(*cmd, "./", 2) == 0 || ft_strncmp(*cmd, "/", 1) == 0 ||  ft_strncmp(*cmd, "../", 2) == 0)
		check = 1;
	if (check == 1)
	{
        if (access(cmd[0], F_OK) == 0)
            *path = cmd[0];
        else
        {
            perror(cmd[0]);
            ft_free_matrix(cmd);
            exit(errno);
        }
    }
    return (check);
}

void	ft_execve(char *av, char **env)
{
	char	**cmd;
	char	*path;
    int     i;

    i = 0;
    path = NULL;
	if (!*av)
		ft_error(av);
	cmd = ft_split(av, ' ');
	if (!cmd)
		ft_free_error(cmd, "malloc");
	if (relative_path(cmd, &path) == 0)
    {
        if (cmd[0])
		    path = path_getter(cmd[0], env);
    }
	if (path && execve(path, cmd, env) == -1)
		ft_free_error(cmd, "exceve");
}
