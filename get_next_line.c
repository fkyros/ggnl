/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:45:04 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/17 00:43:16 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;
	int		bytesRead;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytesRead = 1;
	while (!bytesRead || !hasNextLine(stash))
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		stash = joinBufferWithStash(stash, buffer);
	}
	newLine = extractLineFromStash(stash, line);
	stash = deleteLineFromStash();
	return (line);
}

char	*hasNextLine(char *str)
{
	return (ft_strchr(str, '\n'));
}

char	*joinStashWithBuffer(char *stash, char *buffer)
{
	return (ft_strjoin(stash, buffer));
}

char	*extractLineFromStash(char *stash, char *line)
{
	char	*newLine;
	char	*res;
	int	i;

	 = ft_strchr(stash, '\n');
	i = 0;
	while (newLine && newLine[i] != '\0')
	{
		line[0]
	}
	return (res);
}
