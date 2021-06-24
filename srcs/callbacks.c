#include "so_long.h"

#include <stdio.h>
#include "libft.h"
#include "game.h"
#include "x.h"

int	close_game(t_game *game)
{
	if (game->flg_win)
		printf("%zuTurns Clear!", game->steps);
	else
		ft_putendl_fd("close", 1);
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

int	main_loop(t_game *game)
{
	if (game->flg_render)
	{
		if (player_move(game))
			game->steps++;
		printf("--- %zuT ---\n", game->steps);
		print_map(game);
		printf("\n");
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