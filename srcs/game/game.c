#include "game.h"

#include <stdbool.h>
#include "libft.h"
#include "utils.h"
#include "mlx.h"
#include "error.h"
#include "stage.h"

void	init_player(t_game *game);

t_game	*new_game(char *filepath)
{
	t_game	*game;

	game = ft_xmalloc(sizeof(t_game));
	game->flg_win = false;
	game->flg_render = true;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		error("A problem occurred in mlx_init.");
	game->win = mlx_new_window(game->mlx, 100, 100, "so_long");
	if (game->mlx == NULL)
		error("A problem occurred in mlx_new_widow.");
	game->stage = new_stage(filepath);
	game->player = ft_xmalloc(sizeof(t_player));
	init_player(game);
	return (game);
}

void	init_player(t_game *game)
{
	size_t	x;
	size_t	y;

	game->player->move_x = 0;
	game->player->move_y = 0;
	y = 0;
	while (y < (size_t)game->stage->rows)
	{
		x = 0;
		while (x < (size_t)game->stage->cols)
		{
			if (game->stage->map[y][x] == 'P')
			{
				game->stage->map[y][x] = '0';
				game->player->x = x;
				game->player->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

t_game	*del_game(t_game *game)
{
	free(game->player);
	game->stage = del_stage(game->stage);
	mlx_destroy_window(game->mlx, game->win);
	free(game->mlx);
	free(game);
	return (NULL);
}

bool	player_move(t_game *game)
{
	size_t	new_x;
	size_t	new_y;

	new_x = game->player->x + game->player->move_x;
	new_y = game->player->y + game->player->move_y;
	game->player->move_x = 0;
	game->player->move_y = 0;
	if (game->stage->map[new_y][new_x] == '1')
	{
		ft_putendl_fd("wall", 1);
		return (false);
	}
	if (game->stage->map[new_y][new_x] == 'C')
		game->stage->map[new_y][new_x] = '0';
	game->player->x = new_x;
	game->player->y = new_y;
	return (true);
}

bool	win_check(t_game *game)
{
	if (game->stage->map[game->player->y][game->player->x] != 'E')
		return (false);
	if (stage_count_obj(game->stage, 'C') == 0)
		return (true);
	return (false);
}
