#include "mlx.h"

#include <stdlib.h>
#include "error.h"
#include "x.h"
#include "libft.h"
#include "stage.h"

int	close_game(void)
{
	ft_putstr_fd("close\n", 1);
	exit(0);
}

int	main(int argc, char *argv[])
{
	void	*mlx;
	void	*win;
	t_stage	*stage;

	if (argc != 2)
		error("invalid argument.");
	stage = new_stage(argv[1]);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "so_long");
	mlx_hook(win, XEV_EXIT, MASK_STRUCT_NOTIFY, close_game, NULL);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	free(mlx);
	stage = del_stage(stage);
	return (0);
}
