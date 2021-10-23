#include "stage.h"

#include "error.h"
#include <stddef.h>
#include <fcntl.h>
#include "libft.h"
#include "utils.h"

void	read_ber(char *filepath, t_list **map);
void	read_map(t_stage *stg, t_list *map);

t_stage	*new_stage(char *filepath)
{
	t_list	*map;
	t_list	*save;
	t_stage	*stage;

	map = NULL;
	stage = (t_stage *)ft_xmalloc(sizeof(t_stage));
	read_ber(filepath, &map);
	valid_ber(map);
	save = map;
	read_map(stage, map);
	ft_lstclear(&save, free);
	valid_map(stage);
	return (stage);
}

t_stage	*del_stage(t_stage *stg)
{
	size_t	i;

	(void)stg;
	i = 0;
	while (stg->map[i])
	{
		free(stg->map[i]);
		stg->map[i] = NULL;
		i++;
	}
	free(stg->map);
	free(stg);
	return (NULL);
}

void	read_ber(char *filepath, t_list **map)
{
	int		num;
	char	*line[1];
	int		fd;

	if (filepath == NULL)
		error("No file is specified.");
	if (ft_strncmp(filepath + ft_strlen(filepath) - 4, ".ber", 5))
		error("File extension is not '.ber'.");
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		error("Failed to open().");
	*line = NULL;
	num = 1;
	while (num > 0)
	{
		num = get_next_line(fd, line);
		ft_lstadd_front(map, ft_lstnew(*line));
	}
	if (num == -1 && close(fd) == -1)
		error("Failed to operate the file.");
}

void	read_map(t_stage *stg, t_list *map)
{
	int		rows;

	while (map && ft_strlen(map->content) == 0)
		map = map->next;
	stg->rows = ft_lstsize(map);
	stg->cols = ft_strlen(map->content);
	stg->map = (char **)ft_xmalloc(sizeof(char *) * (stg->rows + 1));
	rows = stg->rows;
	stg->map[rows] = NULL;
	while (rows--)
	{
		stg->map[rows] = ft_strdup((char *)map->content);
		map = map->next;
	}
}

size_t	stage_count_obj(t_stage *stg, char c)
{
	size_t	x;
	size_t	y;
	size_t	rtn;

	rtn = 0;
	y = 0;
	while (y < (size_t)stg->rows)
	{
		x = 0;
		while (x < (size_t)stg->cols)
		{
			if (stg->map[y][x] == c)
				rtn++;
			x++;
		}
		y++;
	}
	return (rtn);
}
