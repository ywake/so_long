#include "game.h"

#include "property.h"
#include "texture.h"
#include "mlx.h"

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

void	draw_texture(t_img *img, int x, int y, t_texture *tx)
{
	int	xx;
	int	yy;
	int	col;

	yy = 0;
	while (yy < TILE_SIZE)
	{
		xx = 0;
		while (xx < TILE_SIZE)
		{
			col = texture_get_color(tx, xx, yy);
			if ((unsigned int)col != 0xFF000000)
				img_put_pixel(img, x * TILE_SIZE + xx, y * TILE_SIZE + yy, col);
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
			if (game->stage->map[y][x] == '1')
				draw_texture(game->img, x, y, game->textures[TX_WALL]);
			else
				draw_texture(game->img, x, y, game->textures[TX_FLOOR]);
			if (game->stage->map[y][x] == 'C')
				draw_texture(game->img, x, y, game->textures[TX_COLLECTIBLE]);
			else if (game->stage->map[y][x] == 'E')
				draw_texture(game->img, x, y, game->textures[TX_EXIT]);
			else if (game->stage->map[y][x] == 'O')
				draw_texture(game->img, x, y, game->textures[TX_OPPO]);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
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
			{
				draw_texture(game->img, x, y, game->textures[TX_FLOOR]);
				if (game->stage->map[y][x] == 'E')
					draw_texture(game->img, x, y, game->textures[TX_EXIT]);
				draw_texture(game->img, x, y,
					game->player->tx[game->frame / 240]);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img->img_ptr, 0, 0);
}
