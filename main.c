#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	if (BONUS == 0 && argc == 5)
		pipex(argv, env);
	else if (BONUS == 1 && argc >= 5)
		pipex_bonus(argc, argv, env);
	else
		ft_error();
	return (0);
}