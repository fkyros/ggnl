/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:45:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/21 13:52:05 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_stash_with_buffer(char *stash, char *buffer)
{
	char	*res;
	int		tam;

	if (stash == NULL && buffer == NULL)
		return (NULL);
	tam = ft_strlen(stash) + ft_strlen(buffer);
	res = (char *) malloc(tam + 1);
	if (res == NULL)
		return (NULL);
	if (stash != NULL)
		copy_string_from_index(stash, res, 0);
	if (buffer != NULL)
		copy_string_from_index(buffer, res, ft_strlen(stash));
	res[tam] = '\0';
	if (stash)
		free(stash);
	return (res);
}

char	*extract_line_from_stash(char *stash, int bytes_read)
{
	char	*res;
	int		tam;
	int		i;

	if (!stash)
		return (NULL);
	if (bytes_read)
		tam = ft_strchr(stash, '\n') - stash + 1;
	else
		tam = ft_strlen(stash);
	if (ft_strlen(stash) == 0)
		return (NULL);
	res = (char *) malloc(tam + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < tam)
	{
		res[i] = *stash;
		i++;
		stash++;
	}
	res[tam] = '\0';
	return (res);
}

char	*delete_line_from_stash(char *stash, int bytes_read)
{
	char	*res;
	char	*remnants;
	int		tam;

	if (!stash)
		return (NULL);
	if (bytes_read)
		remnants = ft_strchr(stash, '\n') + 1;
	else
		remnants = stash;
	tam = ft_strlen(remnants);
	res = (char *) malloc(tam + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, remnants, tam + 1);
	free(stash);
	return (res);
}

int	read_into_buffer(int fd, char *buffer)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (bytes_read);
	buffer[bytes_read] = '\0';
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read_into_buffer(fd, buffer);
		if (!bytes_read)
			break ;
		if (bytes_read < 0)
		{
			(free(stash), stash = NULL);
			return (NULL);
		}
		stash = join_stash_with_buffer(stash, buffer);
	}
	line = extract_line_from_stash(stash, bytes_read);
	stash = delete_line_from_stash(stash, bytes_read);
	if (!bytes_read)
		(free(stash), stash = NULL);
	return (line);
}
