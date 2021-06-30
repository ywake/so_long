#include "game.h"

#include "property.h"

void	draw_rectangle(t_img *img, int x, int y, int color)
{
	int	xx;
	int	yy;

	yy = 0;
	while (yy < TILE_SIZE)
	{
		xx = 0;
		while (xx < TILE_SIZE)
		{
			img_put_pixel(img, x * TILE_SIZE + xx, y * TILE_SIZE + yy, color);
			xx++;
		}
		yy++;
	}
}

void	draw_stage(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->stage->rows)
	{
		x = 0;
		while (x < game->stage->cols)
		{
			if (x == (int)game->player->x && y == (int)game->player->y)
				draw_rectangle(game->img, x, y, C_RED);
			else if (game->stage->map[y][x] == '1')
				draw_rectangle(game->img, x, y, C_WHITE);
			else if (game->stage->map[y][x] == 'C')
				draw_rectangle(game->img, x, y, C_GREEN);
			else if (game->stage->map[y][x] == 'E')
				draw_rectangle(game->img, x, y, C_LBLUE);
			else
				draw_rectangle(game->img, x, y, C_BLACK);
			x++;
		}
		y++;
	}
}
