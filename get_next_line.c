/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:45:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/17 20:30:06 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line_from_stash(char *stash)
{
	char	*res;
	int		tam;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	tam = ft_strchr(stash, '\n') - stash + 1;
	res = (char *) malloc(tam);
	if (!res)
		return (NULL);
	while (i < tam)
	{
		res[i] = *stash;
		i++;
		stash++;
	}
	res[i] = '\0';
	return (res);
}

char	*delete_line_from_stash(char *stash)
{
	char	*res;
	char	*remnants;
	int		tam;

	if (!stash)
		return (NULL);
	remnants = ft_strchr(stash, '\n');
	tam = ft_strlen(++remnants);
	res = (char *) malloc(tam + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, remnants, tam + 1);
	free(stash);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (stash)
				free(stash);
			stash = NULL;
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = join_stash_with_buffer(stash, buffer);
	}
	/*if (bytes_read == 0)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}*/
	line = extract_line_from_stash(stash);
	stash = delete_line_from_stash(stash);
	return (line);
}
