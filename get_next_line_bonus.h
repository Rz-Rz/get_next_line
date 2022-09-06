#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

typedef struct s_list {
  char *content;
  int fd;
  struct s_list *next;
} t_list;

// prototypes
char *get_next_line(int fd);

void read_and_stash(t_list **stash, int *read_ptr, int fd);

void add_to_stash(t_list **stash, char *buff, int read, int fd);

void find_stash_by_fd(t_list **stash, t_list *new_node, int fd);


#endif
