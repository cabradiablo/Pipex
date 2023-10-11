/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:54 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/10 12:44:10 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(char **argv, char **env)
{
	int		fd[2];
	pid_t	child;
    
	if (pipe(fd) < 0)
		ft_error("pipe");
	child_input(fd, argv, env);
	child = child_output(fd, 3, argv, env);
    close(0);
	ft_waitchid(child);
}

void	pipex_bonus(int argc, char **argv, char **env)
{
	int		fd[2];
	int		pos;
	pid_t	child;

	pos = 2;
	if (pipe(fd) < 0)
		ft_error("pipex");
    pos += ft_first_child(fd, argv, env);
	while (argc - 2 > ++pos)
		child_middle(fd, pos, argv, env);
	child = child_output(fd, argc - 2, argv, env);
	close(0);
    if (ft_strncmp(argv[1], "here_doc", 8) == 0)
    {
			    ft_unlink("/here_doc", env);
	}
	ft_waitchid(child);
}
