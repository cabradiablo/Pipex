/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:53:01 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/10 12:27:59 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	perror(s);
	exit(errno);
}

void	ft_error2(char *s)
{
    dprintf(2, "pid: %d\n", getpid());
    dprintf(2, "parent pid: %d\n", getppid());
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command Not Found\n", 2);
	exit(127);
}

void	ft_free_error(char **s, char *r)
{
	ft_free_matrix(s);
	ft_error(r);
}
