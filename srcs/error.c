#include "error.h"

#include <stdlib.h>
#include "logging.h"

void	error(char	*msg)
{
	ft_putendl_fd(RED"Error", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(END, 2);
	exit(EXIT_FAILURE);
}
