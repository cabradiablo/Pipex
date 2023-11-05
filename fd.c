/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:09:01 by alepinto          #+#    #+#             */
/*   Updated: 2023/11/05 10:09:58 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s1[i] && s1[i] == s2[i])
		{
			while (s1[i] && s1[i] == s2[i] && i < n)
				i++;
		}
		else if (i == n - 1)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        else
            return (-300);
	}
	return (0);
}
int ft_check_here_doc(int **fd, int ac, char **av)
{
    int  here_doc;
    char *infile;
    char *outfile;

    here_doc = 0;
    infile = av[1];
    outfile = av[ac - 1];
    if (ft_strncmp("here_doc", infile, 9) == 0)
        here_doc = 1;
    if (here_doc)
        fd[0][0] = ft_heredoc(infile, av[2]);
    else
        fd[0][0] = open(infile, O_RDONLY);
    if (here_doc)
        fd[0][1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0666);
    else
        fd[0][1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    return (here_doc);
}

int	ft_heredoc(char *argv1, char *argv2)
{
	char	*line;
	int		temp_fd;
    
	temp_fd = open(argv1, O_CREAT | O_RDWR | O_TRUNC, 0777);
	while (1)
	{
		ft_putstr_fd("heredoc XD >>", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (ft_strncmp(line, argv2, ft_strlen(argv2) + 1) == 10)
        {
            free(line);
			break ;
        }
		write(temp_fd, line, ft_strlen(line));
		free(line);
	}
	close(temp_fd);
	temp_fd = open(argv1, O_RDONLY);
	return (temp_fd);
}
void    ft_reddirect(int **fd, int flag)
{ 
    if (flag == 1)
    {
        dup2(fd[FILES][READ], STDIN_FILENO);
        dup2(fd[RIGHT][WRITE], STDOUT_FILENO);
        close(fd[2][0]);
        close(fd[2][1]);
    }
    else if (flag == 2)
    {
        dup2(fd[LEFT][READ], STDIN_FILENO);
        dup2(fd[RIGHT][WRITE], STDOUT_FILENO);
        close(fd[1][0]);
        close(fd[1][1]);
    }
    else if (flag == 3)
    {
        dup2(fd[RIGHT][READ], STDIN_FILENO);
        dup2(fd[FILES][WRITE], STDOUT_FILENO);
    }
    else
        exit(9);
}
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
