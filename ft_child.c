/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:53:01 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/27 01:56:00 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

# ifndef FILES
#  define FILES 0
# endif

# ifndef LEFT
#  define LEFT 1
# endif

# ifndef RIGHT
#  define RIGHT 2
# endif

# ifndef READ
#  define READ 0
# endif

# ifndef WRITE
#  define WRITE 1
# endif


void    ft_reddirect(int **fd, int flag)
{ 
    if (flag == 1)
    {
        dprintf(2, "INPUT CHILD READ: %i---", dup2(fd[FILES][READ], STDIN_FILENO));
        dprintf(2, "INPUT CHILD WRITE: %i\n", dup2(fd[RIGHT][WRITE], STDOUT_FILENO));
        close(fd[2][0]);
        close(fd[2][1]);
    }
    else if (flag == 2)
    {
        dprintf(2, "MIDDLE CHILD READ: %i---", dup2(fd[LEFT][READ], STDIN_FILENO));
        dprintf(2, "MIDDLE CHILD WRITE: %i\n", dup2(fd[RIGHT][WRITE], STDOUT_FILENO));
        close(fd[1][0]);
        close(fd[1][1]);
    }
    else if (flag == 3)
    {
        dprintf(2, "OUT CHILD READ: %i----", dup2(fd[RIGHT][READ], STDIN_FILENO));
        dprintf(2, "OUT CHILD WRITE: %i\n", dup2(fd[FILES][WRITE], STDOUT_FILENO));
    }
    else
        exit(9);
}
void	child_input(int **fd, char *av, char **env)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		ft_error("fork");
	if (child == 0)
	{
        ft_reddirect(fd, 1);
		ft_exec(av, env);
	}
	wait(&child);
    close(fd[2][1]);
   // close(fd[2][0]);
    
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
		ft_exec(av, env);
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
		ft_exec(av, env);
	}
	return (child);
}
