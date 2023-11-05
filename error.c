/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:53:01 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/29 02:37:55 by alepinto         ###   ########.fr       */
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
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": command Not Found\n", 2);
	exit(127);
}

void	ft_free_error(char **s, char *r)
{
	ft_free_matrix(s);
	ft_error(r);
}
void	ft_free_matrix(char **matrix)
{
	int	row;

	row = -1;
	while (matrix[++row])
		free(matrix[row]);
	free(matrix);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}