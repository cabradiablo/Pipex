/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:23:37 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/29 16:04:54 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s1, char c)
{
	int	i;

	i = 0;
	if (!*s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}
char    *ft_strjoin(char *head, char *tail)
{
    int     i;
    int     j;
    char    *result;
    
    i = -1;
    j = -1;
    dprintf(2, "%s\n%s\n", head, tail);
    while (head && head[++i])
        ;
    while (tail && tail[++j])
        ;
    if (i == -1 || j == -1)
        return (NULL);
    result = (char *)malloc(i + j + 1);
    if (!result)
        return (NULL);
    result[i + j] = '\0';
    while (--j >= 0)
        result[j + i] = tail[j];
    while (--i >= 0)
        result[i] = head[i];
    return (result);
}