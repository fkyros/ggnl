/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gade-oli <gade-oli@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:13:06 by gade-oli          #+#    #+#             */
/*   Updated: 2023/07/16 23:34:51 by gade-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		tam;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	tam = gnl_strlen(s1) + gnl_strlen(s2) + 1;
	res = (char *) malloc(tam);
	if (res == NULL)
		return (NULL);
	if (s1 != NULL)
		copy_string_from_index(s1, res, 0);
	if (s2 != NULL)
		copy_string_from_index(s2, res, gnl_strlen(s1));
	res[tam - 1] = '\0';
	return (res);
}

int	gnl_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
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
