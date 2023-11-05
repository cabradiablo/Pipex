/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:53:01 by alepinto          #+#    #+#             */
/*   Updated: 2023/11/05 05:40:02 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void	child_input(int **fd, char *av, char **env)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		ft_error("fork");
	if (child == 0)
	{
        ft_reddirect(fd, 1);
		ft_execve(av, env);
	}
    close(fd[2][1]);
    close(fd[2][0]);
    
}

void	child_middle(int **fd, char *av, char **env)
{
	pid_t	child;

    fd[1][0] = fd[2][0];
    fd[1][1] = fd[2][1];
    pipe(fd[2]);
	child = fork();
	if (child < 0)
		ft_error("fork");
	if (child == 0)
	{
        ft_reddirect(fd, 2);
		ft_execve(av, env);
	}
    close(fd[2][1]);
    close(fd[1][0]);
}

pid_t	child_output(int **fd, char *av, char **env)
{
	pid_t	child;
    

	child = fork();
	if (child < 0)
		ft_error("fork");
	if (child == 0)
	{
        ft_reddirect(fd, 3);
		ft_execve(av, env);
	}
	return (child);
}
