#include "error.h"

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "logging.h"

void	error(char	*msg)
{
	ft_putendl_fd(RED"Error", 2);
	ft_putstr_fd(msg, 2);
	ft_putendl_fd(END, 2);
	exit(EXIT_FAILURE);
}

void	pexit(char *msg)
{
	perror(msg);
	exit(1);
}

int	catch_err(int status, char *title)
{
	if (status == -1)
		pexit(title);
	return (status);
}

void	*catch_nul(void *ptr, char *title)
{
	if (ptr == NULL)
		pexit(title);
	return (ptr);
}
