#include "libft.h"

t_list	*ft_lstndup(t_list *list, size_t n)
{
	t_list	*new_list;
	void	*content;

	if (list == NULL || n == 0)
		return (NULL);
	content = malloc(sizeof(void *));
	ft_memcpy(content, list->content, sizeof(void *));
	new_list = ft_lstnew(content);
	if (new_list == NULL)
		return (NULL);
	new_list->next = ft_lstndup(list->next, n - 1);
	return (new_list);
}
