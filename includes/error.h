#ifndef ERROR_H
# define ERROR_H

# define FAIL_MALLOC "Failed to allocate memory."

void	error(char *msg);
void	pexit(char *msg);
int		catch_err(int status, char *title);
void	*catch_nul(void *ptr, char *title);

#endif
