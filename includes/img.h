#ifndef IMG_H
# define IMG_H

# include <stdbool.h>

typedef struct s_img
{
	void	*mlx_ptr;
	void	*img_ptr;
	int		*data;
	int		width;
	int		height;

	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

t_img	*new_img(void *mlx, int width, int height);
t_img	*del_img(t_img *img);

int		img_get_pixel(t_img *img, int x, int y);
bool	img_put_pixel(t_img *img, int x, int y, int color);

#endif
