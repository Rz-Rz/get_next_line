#include "get_next_line_bonus.h"

int found_newline(t_list *stash)
{
		int i;
		t_list *current;

		if (!stash)
				return (0);
		current = lstlast(stash); 
		i = 0;
		while (current->content[i])
		{
				if (current->content[i] == '\n')
						return (1);
				i++;
		}
		return (0);
}

void generate_line(char **line, t_list *stash)
{
		int i;
		int len;

		len = 0;
		while (stash)
		{
				i = 0;
				while (stash->content[i])
				{

						len++;
						if (stash->content[i] == '\n')
								break;
						i++;
				}
				stash = stash->next;
		}
		*line = malloc(sizeof(char) * (len + 1));
}

void free_stash(t_list *stash)
{
		t_list *current;
		t_list *next;

		current = stash;
		while (current)
		{
				free(current->content);
				next = current->next;
				free(current);
				current = next;
		}
}

t_list	*lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int ft_strlen(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}