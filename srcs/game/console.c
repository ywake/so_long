#include "so_long.h"

#include "libft.h"

void	print_map(t_game *game)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < (size_t)game->stage->rows)
	{
		x = 0;
		while (x < (size_t)game->stage->cols)
		{
			if (x == game->player->x && y == game->player->y)
				ft_putstr_fd("P", 1);
			else
				write(1, &game->stage->map[y][x], 1);
			x++;
		}
		ft_putstr_fd("\n", 1);
		y++;
	}
}
