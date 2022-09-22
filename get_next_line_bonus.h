/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:36:10 by kdhrif            #+#    #+#             */
/*   Updated: 2022/09/22 15:28:13 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#define OPEN_MAX 1024

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

//prototypes
char				*get_next_line(int fd);

void				read_and_stash(t_list **stash, int *read_ptr, int fd);

void				add_to_stash(t_list **stash, char *buff, int read);

void				extract_line(t_list *stash, char **line);

void				clean_stash(t_list **stash);

t_list				*lstlast(t_list *lst);

void				generate_line(char **line, t_list *stash);

void				free_stash(t_list *stash);

int					found_newline(t_list *stash);

int					ft_strlen(char *c);

#endif
