#include "texture.h"

#include <stdlib.h>
#include "property.h"
#include "utils.h"
#include "mlx.h"
#include "error.h"

t_texture	*new_texture(void *mlx, char *filepath)
{
	t_texture	*tx;

	tx = (t_texture *)ft_xmalloc(sizeof(t_texture));
	tx->img_ptr = mlx_xpm_file_to_image(mlx, filepath, &tx->width, &tx->height);
	if (tx->img_ptr == NULL)
		error("Failed to load the image.");
	tx->data = (int *)mlx_get_data_addr(
			tx->img_ptr, &tx->bpp, &tx->size_l, &tx->endian);
	if (tx->data == NULL)
		error("Failed to load the image data.");
	return (tx);
}

t_texture	*del_texture(void *mlx, t_texture *tx)
{
	mlx_destroy_image(mlx, tx->img_ptr);
	free(tx);
	return (NULL);
}

t_texture	**new_textures(void *mlx)
{
	t_texture	**txs;

	txs = (t_texture **)ft_xmalloc(sizeof(t_texture *) * 6);
	txs[TX_COLLECTIBLE] = new_texture(mlx, PATH_COLLECTIBLE);
	txs[TX_EXIT] = new_texture(mlx, PATH_EXIT);
	txs[TX_FLOOR] = new_texture(mlx, PATH_FLOOR);
	txs[TX_WALL] = new_texture(mlx, PATH_WALL);
	txs[TX_OPPO] = new_texture(mlx, PATH_OPPO);
	txs[5] = NULL;
	return (txs);
}

t_texture	**del_textures(void *mlx, t_texture **txs)
{
	int	i;

	i = 0;
	while (txs[i])
	{
		txs[i] = del_texture(mlx, txs[i]);
		i++;
	}
	free(txs);
	return (NULL);
}

int	texture_get_color(t_texture *tx, int x, int y)
{
	if (!(0 <= x && x < tx->width) || !(0 <= y && y < tx->height))
		return (-1);
	return (tx->data[y * tx->width + x]);
}
