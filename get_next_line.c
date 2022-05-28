#include "libft/libft.h"
#include "get_next_line.h"

char *get_next_line(int fd)
{
		static t_list *stash = NULL;
		char *line;
		int read;

		if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
				return (NULL);

		read = 1;
		line = NULL;
		// 1. read from fd and add to linked list
		read_and_stash(&stash, &read, fd);
		if (!stash)
				return (NULL);
		// 2. extract from stash to line 
		extract_line(stash, &line);	
		// 3. clean up stash
		clean_stash(&stash);
		
		return (line);
}

void read_and_stash(t_list **stash, int *read_ptr, int fd)
{
		char *buff;

		while (!ft_found_newline(*stash) && *read_ptr != 0)
		{
				buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
				if (!buff)
						return;

				*read_ptr = (int)read(fd, buff, BUFFER_SIZE);
				if ((!*stash && !*read_ptr) || *read_ptr == -1)
				{
						free(buff);
						return;
				}
				buff[*read_ptr] = '\0';
				add_to_stash(stash, buff, read_ptr);
				free(buff);
		}
}


void add_to_stash(t_list **stash, *buff, read)
{
		int i;
		t_list *current;
		t_list *new_node;

		new_node = malloc(sizeof(t_list));
		if (new_node == NULL)
				return;
		new_node->next = NULL;
		new_node->content = malloc(sizeof(char) * (read + 1));
		if (!new_node->content)
				return (NULL);
		i = 0;
		while (buff[i] && i < read)
		{
				new_node->content[i] = buff[i];
				i++;
		}
		new_node->content[i] = '\0';
		if (*stash == NULL)
		{
				*stash == new_node;
				return;
		}
		last = ft_lstlast(stash);
		last->next = new_node;
}

void extract_line(t_list *stash, **line)
{
		int i;
		int j;

		if (!stash)
				return;
		generate_line(stash, line);
		if (*line == NULL)
				return;
		j = 0;
		while(stash)
		{ 
				i = 0;
				while (stash->content[i])
				{
						if (stash->content[i] == '\n')
						{
								(*line)[j++] = stash->content[i];
								break;
						}
						(*line)[j++] = stash->content[i++];
				}
				stash = stash->next;
		}
		(*line)[j] = '\0';
}

void clean_stash(t_list **stash)
{
		t_list *last;
		t_list *clean_node;
		int i;
		int j;

		clean_node = malloc(sizeof(t_list));
		if (!clean_node)
				return;
		clean_node->next = NULL;
		last = ft_lstlast(stash);
		i = 0;
		while (last->content[i] && last->content[i] != '\n')
				i++;
		if (last->content && last->content[i] == '\n')
				i++;
		clean_node->content = malloc(sizeof(char) * (ft_strlen(last->content) - i + 1)); 
		if (!clean_node->content)
				return;
		j = 0;
		while (last->content[i])
				clean_node->content[j++] = last->content[i++];
		clean_node->content[j] = '\0';
		free_stash(*stash);
		*stash = clean_node; 

}
