#include "game.h"

#include "property.h"

void	init_player_texture(t_game *game)
{
	game->player->tx[0] = new_texture(game->mlx, PATH_PLAYER_0);
	game->player->tx[1] = new_texture(game->mlx, PATH_PLAYER_1);
	game->player->tx[2] = new_texture(game->mlx, PATH_PLAYER_2);
	game->player->tx[3] = new_texture(game->mlx, PATH_PLAYER_3);
	game->player->tx[4] = new_texture(game->mlx, PATH_PLAYER_4);
	game->player->tx[5] = new_texture(game->mlx, PATH_PLAYER_5);
}

void	del_player_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->player->tx[i] = del_texture(game->mlx, game->player->tx[i]);
		i++;
	}
}
