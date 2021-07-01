#ifndef TEXTURE_H
# define TEXTURE_H

enum			e_texture
{
	TX_COLLECTIBLE,
	TX_EXIT,
	TX_FLOOR,
	TX_WALL
};

typedef struct s_texture
{
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;

	int		size_l;
	int		bpp;
	int		endian;
}	t_texture;

t_texture	*new_texture(void *mlx, char *filepath);
t_texture	*del_texture(void *mlx, t_texture *tx);
t_texture	**new_textures(void *mlx);
t_texture	**del_textures(void *mlx, t_texture **txs);
int			texture_get_color(t_texture *tx, int x, int y);

#endif
