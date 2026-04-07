/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:53:16 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/07 21:11:19 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_function(int fd, char *stash)
{
	char	*buffer;
	int		bytes;
	char	*tmp;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buffer);
			if (bytes == 0 && stash && *stash)
				return (stash);
			return (free(stash), NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	return (free(buffer), stash);
}

char	*ft_getline(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	line = ft_calloc(len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*ft_getrest(char *stash)
{
	char	*rest;
	int		len;
	int		i;
	int		j;

	i = -1;
	len = 0;
	while (stash[len])
	{
		if (stash[len] == '\n' && i == -1)
			i = len;
		len++;
	}
	if (i == -1)
		return (free(stash), NULL);
	i++;
	rest = ft_calloc(len - i + 1, sizeof(char));
	if (!rest)
		return (NULL);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	return (free(stash), rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_function(fd, stash);
	if (!stash)
		return (NULL);
	line = ft_getline(stash);
	stash = ft_getrest(stash);
	return (line);
}
