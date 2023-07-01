#include "libft.h"

void	ft_free_matrix(char **matrix)
{
	int	row;

	row = -1;
	while (matrix[++row]);
	while (--i >= 0)
		free(matrix[i]);
	free(matrix);
}
