#ifndef STAGE_H
# define STAGE_H

typedef struct s_stage
{
	char	**map;
	int		cols;
	int		rows;
}	t_stage;

t_stage	*new_stage(char *filepath);
t_stage	*del_stage(t_stage *stage);
void	valid_map(t_stage *stage);

#endif
