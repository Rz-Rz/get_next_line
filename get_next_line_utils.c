#include "get_next_line.h"

int ft_found_newline(t_list *stash)
{
		int i;
		t_list *current;

		if (!stash)
				return (NULL);
		current = ft_lstlast(stash); 
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
				while (stash->content[i])
				{

						if (stash->content[i] == '\n')
						{
								len++;
								break;
						}
						len++;
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
				free(current->content);
				current = next;
		}
}
