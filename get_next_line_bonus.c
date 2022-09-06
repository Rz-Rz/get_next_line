#include "get_next_line_bonus.h"

char *get_next_line(int fd) {
  static t_list *stash = NULL;
char *line;
  int readval;

  if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
    return (NULL);
  readval = 1;
  line = NULL;
  // 1. read from fd and add to linked list
  read_and_stash(&stash, &readval, fd);
  if (!stash)
    return (NULL);
  // 2. extract from stash to line
  // 3. clean up stash

  return (line);
}

void read_and_stash(t_list **stash, int *read_ptr, int fd) {
  char *buff;
  t_list *cur;
  t_list *tmp;

  while (!found_newline(*stash) && *read_ptr) {
    buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buff)
      return;
    *read_ptr = (int)read(fd, buff, BUFFER_SIZE);
    if ((!*stash && !*read_ptr) || *read_ptr == -1) {
      free(buff);
      return;
    }
    buff[*read_ptr] = '\0';
    create_stash(&tmp, buff, *read_ptr, fd);
    free(buff);
  }
}

void create_stash(t_list **stash, char *buff, int readval, int fd) {
  int i;
  t_list *new_node;

  new_node = malloc(sizeof(t_list));
  if (new_node == NULL)
    return;
  new_node->next = NULL;
  new_node->content = malloc(sizeof(char) * (readval + 1));
  new_node->fd = fd;
  if (!new_node->content)
    return;
  i = 0;
  while (buff[i] && i < readval) {
    new_node->content[i] = buff[i];
    i++;
  }
  new_node->content[i] = '\0';
  if (*stash == NULL) {
    *stash = new_node;
    return;
  }
  find_stash_by_fd(stash, new_node, fd);
  // (*stash)->next = new_node;
}

void find_stash_by_fd(t_list **stash, t_list *new_node, int fd) {

}