#include "mlx.h"

int	main(void)
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 100, 100, "so_long");
	mlx_loop(mlx);
	return (0);
}
