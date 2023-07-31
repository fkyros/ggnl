/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:59:27 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/31 17:08:15 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	copy_string_from_index(const char *src, char *dst, int i);

int		read_into_buffer(int fd, char *buffer);
char	*extract_line_from_stash(char *stash, int bytes_read);
char	*join_stash_with_buffer(char *stash, char *buffer);
char	*delete_line_from_stash(char *stash, int bytes_read);

#endif
