/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiozsert <wiozsert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 14:56:05 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 13:55:25 by wiozsert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>

typedef struct			s_node
{
	int					s_fd;
	char				*s_line;
	struct s_node		*next;
}						t_node;

int						free_book(int fd, t_node **book, int i);
char					*strsjoin(char *str1, char *str2, int i, int len);
char					*get_line_in_rest(t_node *book, char *buffer, int i,
	size_t is_eof);
char					*get_rest(t_node *book, char *buffer, int i);
char					*get_next_rest(t_node *book, char *buffer, int i,
	size_t is_eof);
char					*get_line(t_node *book, char *line, int len,
	char *buffer);
char					*first_node(const int fd, char *line, t_node **book);
char					*new_node(const int fd, char *line, t_node **book);
char					*current_node(char *line, t_node *book);
int						get_next_line(const int fd, char **line);

#endif
