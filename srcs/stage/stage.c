#include "stage.h"

#include "error.h"
#include <stddef.h>
#include <fcntl.h>
#include "libft.h"
#include "utils.h"

void	open_ber(char *filepath, t_stage *stg, t_list **map);
void	read_map(t_stage *stg, t_list *map);
void	valid_map(t_stage *stg);

void	print_map(char **map)
{
	int	len;
	int	i;

	len = ft_strcount(map);
	i = 0;
	while (i < len)
	{
		ft_putendl_fd(map[i], 1);
		i++;
	}
}

t_stage	*new_stage(char *filepath)
{
	t_list	*map;
	t_list	*save;
	t_stage	*stage;

	map = NULL;
	stage = (t_stage *)ft_xmalloc(sizeof(t_stage));
	open_ber(filepath, stage, &map);
	save = map;
	read_map(stage, map);
	ft_lstclear(&save, free);
	print_map(stage->map);
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

void	open_ber(char *filepath, t_stage *stg, t_list **map)
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
	stg->cols = -1;
	stg->rows = 0;
	while (set_rtn_int(&num, get_next_line(fd, line)) > 0)
	{
		if (stg->cols != -1 && stg->cols != (int)ft_strlen(*line))
			error("The map must be rectangular.");
		stg->cols = (int)ft_strlen(*line);
		ft_lstadd_front(map, ft_lstnew(*line));
		stg->rows++;
	}
	if (num == -1 && close(fd) == -1)
		error("Failed to operate the file.");
	free(*line);
}

void	read_map(t_stage *stg, t_list *map)
{
	int		rows;

	stg->map = (char **)ft_xmalloc(sizeof(char *) * (stg->rows + 1));
	rows = stg->rows;
	stg->map[rows] = NULL;
	while (rows--)
	{
		stg->map[rows] = ft_strdup((char *)map->content);
		map = map->next;
	}
}
