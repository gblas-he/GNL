/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:53:16 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/04 18:37:49 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*read_function(int fd, char *stash)
{
	char	*buffer;
	int		bytes;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!stash || !ft_strchr(stash, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		stash = ft_strjoin(stash, buffer);
	}
	// printf("stash->%s, buffer->%s\n", stash, buffer);
	free(buffer);
	return (stash);
}

char	*ft_getline(char *stash)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (stash[len] && stash[len] != '\n')
		len++;
	if (stash[len] != '\n')
		len++;
	line = ft_calloc(stash[len] + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = stash[i];
		i++;
	}
	// while (*stash && !ft_strchr(stash, '\n'))
	// {
	// 	line = ft_calloc(ft_strlen(stash), sizeof(char));
	// 	line = ft_strdup(stash);
	// }
	// i = 0;
	// while (*stash && *stash != '\n')
	// 	i++;
	// line = ft_calloc(ft_strlen(stash) + 1, sizeof(char));
	// line = ft_strdup(stash);
	// while (stash[i] && stash[i] != '\n')
	// {
	// 	line[i] = stash[i];
	// 	i++;
	// }
	printf("prueba line--> %s, prueba stash--> %s\n", line, stash);
	return (line);
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
	// printf("prueba gnl--> %s\n", gnl);
	return (line);
}

int	main(void)
{
	__attribute__((unused)) int fd = open("ex.txt", O_RDONLY);
	__attribute__((unused)) char *str;
	//__attribute__((unused)) char *first = NULL;
	__attribute__((unused)) int count = 0;
	if (fd == -1)
	{
		printf("error");
		return (-1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		/* 		if (first == NULL)
					first = strdup(str); */
		count++;
		printf("main: [%d] %s\n", count, str);
		free(str);
	}
	// printf("\n1º buffer: %s", first);
	// free(first);
	close(fd);
	return (0);
}