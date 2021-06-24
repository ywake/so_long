#ifndef GAME_H
# define GAME_H

# include <sys/types.h>
# include <stdbool.h>
# include "stage.h"

typedef struct s_player
{
	size_t	x;
	int		move_x;
	size_t	y;
	int		move_y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_stage		*stage;
	t_player	*player;
	size_t		steps;
	bool		flg_render;
	bool		flg_win;
}	t_game;

t_game	*new_game(char *filepath);
t_game	*del_game(t_game *game);
bool	player_move(t_game *game);
bool	win_check(t_game *game);

#endif
