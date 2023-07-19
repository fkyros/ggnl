/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:45:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/19 21:47:40 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		remnants = ft_strchr(stash, '\n')  + 1;
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

char	*get_next_line(int fd)
{
	static char	*stash[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(stash[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			break;
		if (bytes_read < 0)
		{
			if (stash[fd])
				free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash[fd] = join_stash_with_buffer(stash[fd], buffer);
	}
	line = extract_line_from_stash(stash[fd], bytes_read);
	stash[fd] = delete_line_from_stash(stash[fd], bytes_read);
	if (!bytes_read && stash[fd])
	{
		free(stash[fd]);
		stash[fd] = NULL;
	}
	return (line);
}
