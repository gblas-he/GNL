/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:53:16 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/09 12:55:23 by marvin           ###   ########.fr       */
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
			if (bytes < 0 || !stash || !*stash)
				return (free(stash), NULL);
			return (stash);
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
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	return (line);
}

char	*ft_getrest(char *stash)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	rest = ft_calloc(ft_strlen(stash + i) + 1, sizeof(char));
	if (!rest)
		return (free(stash), NULL);
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
	if (!line)
		return (free(stash), NULL);
	stash = ft_getrest(stash);
	return (line);
}
