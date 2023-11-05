/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alepinto <alepinto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 20:52:48 by alepinto          #+#    #+#             */
/*   Updated: 2023/10/29 02:47:25 by alepinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	main(int ac, char **av, char **env)
{
	if (BONUS == 0 && ac == 5)
		pipex(ac, av, env);
	else if (BONUS == 1 && ac >= 5)
		pipex_bonus(ac, av, env);
	else
		ft_putstr_fd("INVALID ARGUMENTS", 2);
	return (0);
}
