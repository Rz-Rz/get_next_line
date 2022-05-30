#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 5
# endif

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;



//prototypes
char *get_next_line(int fd);

void read_and_stash(t_list **stash, int *read_ptr, int fd);

void add_to_stash(t_list **stash, char *buff, int read);

void extract_line(t_list *stash, char **line);

void clean_stash(t_list **stash);

t_list	*lstlast(t_list *lst);

void generate_line(char **line, t_list *stash);

void free_stash(t_list *stash);

int found_newline(t_list *stash);

int ft_strlen(char *c);




#endif
