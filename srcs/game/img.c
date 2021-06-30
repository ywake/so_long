#include "img.h"

#include <stdlib.h>
#include <stdbool.h>
#include "mlx.h"
#include "utils.h"
#include "error.h"

t_img	*new_img(void *mlx, int width, int height)
{
	t_img	*img;

	img = ft_xmalloc(sizeof(t_img));
	img->mlx_ptr = mlx;
	img->width = width;
	img->height = height;
	img->img_ptr = mlx_new_image(mlx, width, height);
	if (img->img_ptr == NULL)
		error("A problem occurred in mlx_new_image.");
	img->data = (int *)mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size_l,
			&img->endian);
	if (img->data == NULL)
		error("A problem occurred in mlx_get_data_addr.");
	return (img);
}

t_img	*del_img(t_img *img)
{
	mlx_destroy_image(img->mlx_ptr, img->img_ptr);
	free(img);
	return (NULL);
}

int	img_get_pixel(t_img *img, int x, int y)
{
	int	color;

	if ((0 <= x && x < img->width) && (0 <= y && y < img->height))
	{
		color = img->data[y * (img->size_l / 4) + x];
		return (color);
	}
	return (-1);
}

bool	img_put_pixel(t_img *img, int x, int y, int color)
{
	if ((0 <= x && x < img->width) && (0 <= y && y < img->height))
	{
		img->data[y * (img->size_l / 4) + x] = color;
		return (true);
	}
	return (false);
}
