#include "so_long.h"

#include <stdlib.h>
#include "error.h"
#include "mlx.h"
#include "x.h"
#include "libft.h"
#include "stage.h"

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		error("invalid argument.");
	game = new_game(argv[1]);
	mlx_hook(game->win, XEV_KEY_PRESS, MASK_PRESS, press_key, game);
	mlx_hook(game->win, XEV_EXIT, MASK_STRUCT_NOTIFY, close_game, game);
	mlx_hook(game->win, XEV_EXPOSE, MASK_EXPOSURE, expose, game);
	mlx_loop_hook(game->mlx, main_loop, game);
	mlx_loop(game->mlx);
	game = del_game(game);
	return (0);
}
