#include "so_long.h"

#include <stdio.h>
#include "libft.h"
#include "game.h"
#include "x.h"

int	close_game(t_game *game)
{
	if (game->flg_win)
		printf("%zu Turns Clear!\n", game->steps);
	else
		ft_putendl_fd("bye!", 1);
	del_game(game);
	exit(0);
}

int	press_key(int key, t_game *game)
{
	if (key == KEY_ESC)
		close_game(game);
	if (key == KEY_W)
		game->player->move_y = -1;
	if (key == KEY_S)
		game->player->move_y = +1;
	if (key == KEY_A)
		game->player->move_x = -1;
	if (key == KEY_D)
		game->player->move_x = +1;
	game->flg_render = true;
	return (0);
}

bool	win_check(t_game *game)
{
	if (game->stage->map[game->player->y][game->player->x] != 'E')
		return (false);
	if (stage_count_obj(game->stage, 'C') == 0)
		return (true);
	return (false);
}

int	main_loop(t_game *game)
{
	if (game->flg_render)
	{
		if (player_move(game))
			game->steps++;
		printf("--- %zuT ---\n", game->steps);
		print_map(game);
		printf("\n");
		game_render(game);
		game->flg_render = false;
		if (win_check(game))
		{
			game->flg_win = true;
			close_game(game);
		}
	}
	return (0);
}

int	expose(t_game *game)
{
	game->flg_render = true;
	return (0);
}
