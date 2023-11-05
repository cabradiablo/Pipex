/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:33 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/29 15:59:46 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BONUS
#  define BONUS 0
# endif

# include "macros.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <errno.h>


//pipex.c
int     **ft_init(void);
void	pipex(int ac, char **av, char **env);
void	pipex_bonus(int ac, char **av, char **env);
void	ft_waitchid(pid_t child);

//child.c
void	child_input(int **fd, char *av, char **env);
void	child_middle(int **fd, char *av, char **env);
pid_t	child_output(int **fd, char *av, char **env);

//exceve.c
int		path_checker(char **env);
char	*path_getter(char *cmd, char **env);
int		relative_path(char **cmd, char **path);
void	ft_execve(char *av, char **env);

//error.c
void	ft_putstr_fd(char *s, int fd);
void	ft_error(char *s);
void	ft_error2(char *s);
void	ft_free_matrix(char **matrix);
void    ft_free_error(char **s, char *r);

//fd.c
int     ft_check_here_doc(int **fd, int ac, char **av);
int		ft_heredoc(char *infile, char *delimeter);
void    ft_reddirect(int **fd, int flag);
void	ft_unlink(char *file, char **env);

//utils_lib.c
int	    ft_strncmp(char *s1, char *s2, int n);
char	**ft_split(char *s, char c);

//get_next_line.c
char	*ft_strjoin(char *s1, char *s2);
int     ft_strchr(char *s1, char c);
int	    ft_strlen(char *s);
char	*get_next_line(int fd);
#endif
