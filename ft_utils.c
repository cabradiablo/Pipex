/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:50 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/23 18:46:39 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void	ft_unlink(char *file, char **env)
{
	char	*path_fd;
	int		i;

	i = -1;
	while (env && env[++i])
	{
		if (env && ft_strncmp("PWD=", env[i], 4) == 0)
			path_fd = ft_strjoin(env[i] + 4, file);
	}
	unlink(path_fd);
	free(path_fd);
}

int	ft_relative_path(char **cmd, char **path)
{
	int	check;
    
    if (*cmd == NULL)
        return (0);
	check = 0;
    if (ft_strncmp(*cmd, "./", 2) == 0 || ft_strncmp(*cmd, "/", 1) == 0 ||  ft_strncmp(*cmd, "./", 2) == 0)
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

void	ft_exec(char *argv, char **env)
{
	char	**cmd;
	char	*path;
    int     i;

    i = 0;
    path = NULL;
	if (!*argv)
		ft_error(argv);
	cmd = ft_split(argv, ' ');
	if (!cmd)
		ft_free_error(cmd, "malloc");
	if (ft_relative_path(cmd, &path) == 0)
    {
        if (cmd[0])
		    path = path_getter(cmd[0], env);
    }
	if (path && execve(path, cmd, env) == -1)
		ft_free_error(cmd, "exceve");
}

void	ft_waitchid(pid_t child)
{
	int	status;
	int	pid;
	int	exit_status;

	pid = 1;
	while (pid != -1)
	{
		pid = waitpid(-1, &status, 0);
		if (pid == child)
		{
			if (WIFEXITED(status))
				exit_status = WEXITSTATUS(status);
		}
	}
	exit(exit_status);
}
