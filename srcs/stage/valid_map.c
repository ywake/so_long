#include "stage.h"

#include <stdbool.h>
#include "libft.h"
#include "error.h"

typedef struct s_count
{
	int	collectible;
	int	exit;
	int	player;
}	t_count;

bool	is_surround(t_stage *stg)
{
	int	i;

	i = 0;
	while (i < stg->cols)
	{
		if (stg->map[0][i] != '1' || stg->map[stg->rows - 1][i] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < stg->rows)
	{
		if (stg->map[i][0] != '1' || stg->map[i][stg->cols - 1] != '1')
			return (false);
		i++;
	}
	return (true);
}

void	valid_map_line(char *line, t_count *c)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strchr("01CEP", line[i]) == NULL)
			error("MAP: Unusable characters are used.");
		if (line[i] == 'C')
			c->collectible++;
		if (line[i] == 'E')
			c->exit++;
		if (line[i] == 'P')
			c->player++;
		i++;
	}
}

void	valid_map(t_stage *stg)
{
	int		i;
	t_count	c;

	if (stg->cols * stg->rows == 0)
		error("MAP: No map.");
	i = 0;
	c.collectible = 0;
	c.exit = 0;
	c.player = 0;
	while (stg->map[i])
		valid_map_line(stg->map[i++], &c);
	if (c.collectible < 1)
		error("MAP: Num of collectible is incorrect.");
	if (c.exit < 1)
		error("MAP: Num of exit is incorrect.");
	if (c.player != 1)
		error("MAP: Num of players is incorrect.");
	if (!is_surround(stg))
		error("MAP: Not surrounded by walls.");
}
