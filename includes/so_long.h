#ifndef SO_LONG_H
# define SO_LONG_H

# include "game.h"

int		close_game(t_game *game);
int		press_key(int key, t_game *game);
int		expose(t_game *game);
int		main_loop(t_game *game);

void	print_map(t_game *game);

#endif
