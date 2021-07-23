#include "so_long.h"

#include <stdio.h>
#include "libft.h"
#include "game.h"
#include "x.h"
#include "logging.h"

int	close_game(t_game *game)
{
	if (game->flg_win == 1)
		printf("%zuTurns Clear!\n", game->steps);
	else if (game->flg_win == -1)
		printf("%zuTurns "RED"You Lose!!\n"END, game->steps);
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

int	win_check(t_game *game)
{
	if (game->stage->map[game->player->y][game->player->x] == 'O')
		return (-1);
	if (game->stage->map[game->player->y][game->player->x] != 'E')
		return (0);
	if (stage_count_obj(game->stage, 'C') == 0)
		return (1);
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
		game->flg_win = win_check(game);
		if (game->flg_win)
			close_game(game);
	}
	draw_player(game);
	game->frame = (game->frame + 1) % 1440;
	return (0);
}

int	expose(t_game *game)
{
	game->flg_render = true;
	return (0);
}
