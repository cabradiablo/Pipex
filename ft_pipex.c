/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:54 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/27 02:02:01 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int **ft_init(void)
{
    int **fd;
    int i;

    i = 0;
    fd = (int **)malloc(3 * sizeof(int *));
    if (!fd)
        return (NULL);
    while (i < 3)
        fd[i++] = (int *)malloc(2 * sizeof(int));
    return (fd);
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

int ft_check_here_doc(int ***fd, int ac, char **av)
{
    int  here_doc;
    char *infile;
    char *outfile;

    here_doc = 0;
    infile = av[1];
    outfile = av[ac - 1];
    dprintf(2, "archivo: %s\n", outfile);
    
    if (ft_strncmp("here_doc", infile, 9) == 0)
        here_doc = 1;
    if (here_doc)
        *fd[0][0] = ft_heredoc(infile, av[2]);
    else
        *fd[0][0] = open(infile, O_RDONLY);
    if (here_doc)
        *fd[0][1] = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0666);
    else
        *fd[0][1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    return (here_doc);
}
void	pipex(int ac, char **av, char **env)
{
	int		**fd;
	pid_t	child;
    int     here_doc;
    
    fd = ft_init();
    here_doc = ft_check_here_doc(&fd, ac, av);
    dprintf(2, "infile: %i   outfile: %i\n" , fd[0][0], fd[0][1]); 
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
	here_doc = ft_check_here_doc(&fd, ac, av);
    dprintf(2, "infile: %i   outfile: %i\n" , fd[0][0], fd[0][1]);
	if (pipe(fd[2]) < 0)
		ft_error("pipex");
    child_input(fd, av[2 + here_doc], env);
    pos += here_doc;
	while (ac - 2 > ++pos)
		child_middle(fd, av[pos], env);
	child = child_output(fd, av[ac -2], env);
    if (here_doc)
        unlink("here_doc");
	ft_waitchid(child);
}
