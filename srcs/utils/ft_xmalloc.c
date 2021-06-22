#include "utils.h"

#include <stdlib.h>
#include "error.h"

void	*ft_xmalloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		error("xmalloc: zero size.");
	ptr = malloc(size);
	if (ptr == NULL)
		error("xmalloc: "FAIL_MALLOC);
	return (ptr);
}
