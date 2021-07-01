#ifndef GAME_H
# define GAME_H

# include <sys/types.h>
# include <stdbool.h>
# include "stage.h"
# include "img.h"
# include "texture.h"

typedef struct s_player
{
	size_t		x;
	size_t		y;
	int			move_x;
	int			move_y;
	t_texture	*tx;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_stage		*stage;
	t_player	*player;
	t_img		*img;
	t_texture	**textures;
	size_t		steps;
	bool		flg_render;
	int			flg_win;
}	t_game;

t_game	*new_game(char *filepath);
t_game	*del_game(t_game *game);
bool	player_move(t_game *game);
void	game_render(t_game *game);
void	draw_stage(t_game *game);

#endif
