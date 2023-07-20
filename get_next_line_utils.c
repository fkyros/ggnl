/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:13:06 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/20 17:48:01 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	if (!s)
		return (NULL);
	while (!found && s[i])
	{
		if (s[i] == (char)c)
			found = 1;
		else
			i++;
	}
	if ((char)c == '\0' && s[i] == '\0')
		found = 1;
	if (found)
		return ((char *)(s + i));
	return (NULL);
}

void	copy_string_from_index(const char *src, char *dst, int i)
{
	int	j;

	j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		j++;
		i++;
	}
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (i);
	if (!dstsize)
		dst = NULL;
	if (dstsize > 0)
	{
		while (src[i] && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
