/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lib.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 02:24:09 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/29 02:53:09 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char *s, int start, int len)
{
	int	out_len;
	char	*save;
	char	*out;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	out_len = ft_strlen(s + start);
	if (out_len < len)
		len = out_len;
	out = malloc(len + 1);
	if (!out)
		return (NULL);
	save = out;
	s += start;
	while (*s && len--)
		*out++ = *s++;
	*out = '\0';
	return (save);
}

static int	ft_security(char **matrix, int row)
{
	if (!matrix[row])
	{
		while (row--)
			free(matrix[row]);
		free(matrix);
		return (1);
	}
	return (0);
}

static int	ft_seglen(char *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static int	ft_segcount(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
    if (!s)
        return (0);
	while (s[i])
	{
		if (s[i] != c && ((s[i + 1] == c) || (s[i + 1] == '\0')))
				count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		row;
	char	**matrix;

	i = 0;
	row = ft_segcount(s, c);
	if (!s || !row)
		return (NULL);
	matrix = malloc(sizeof(char *) * (row + 1));
	if (matrix == NULL)
		return (NULL);
	while (--row >= 0)
	{
		if (s[i] != c)
		{
			matrix[row] = ft_substr(s, i, ft_seglen(s, c, i));
			if (ft_security(matrix, row) == 1)
				return (NULL);
			i += ft_seglen(s, c, i);
		}
		else
			i++;
	}
	matrix[ft_segcount(s, c)] = NULL;
	return (matrix);
}
