/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:46:30 by alepinto          #+#    #+#             */
/*   Updated: 2023/11/01 22:58:34 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int ac, char **av, char **env)
{
	int		**fd;
	pid_t	child;
    int     here_doc;
    
    fd = ft_init();
    here_doc = ft_check_here_doc(fd, ac, av);
	if (pipe(fd[2]) < 0)
		ft_error("pipe");
	child_input(fd, av[2 + here_doc], env);
	child = child_output(fd, av[ac -2], env);
    if (here_doc)
        unlink("here_doc");
	ft_waitchid(child);
}

void	pipex_bonus(int ac, char **av, char **env)
{
	int		**fd;
	int		pos;
    int     here_doc;
	pid_t	child;

    fd = ft_init();
	pos = 2;
	here_doc = ft_check_here_doc(fd, ac, av);
	if (pipe(fd[2]) < 0)
		ft_error("pipex");
    child_input(fd, av[2 + here_doc], env);
    pos += here_doc;
	while (ac - 2 > ++pos)
		child_middle(fd, av[pos], env);
	child = child_output(fd, av[ac - 2], env);
    if (here_doc)
        unlink("here_doc");
	ft_waitchid(child);
}
int **ft_init(void)
{
    int i;
    int **fd;

    i = 0;
    fd = (int **)malloc(3 * sizeof(int *));
    if (!fd)
        return (NULL);
    while (i < 3)
        fd[i++] = (int *)malloc(2 * sizeof(int));
        return (fd);
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
