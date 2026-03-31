/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:53:16 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/31 19:18:34 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(3 + 1, sizeof(char *));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (bytes_read <= 0)
		return (NULL);
	return (buffer);
}

int	main(void)
{
	int fd = open("ex.txt", O_RDONLY);
	char *str;
	char *first = NULL;
	while ((str = get_next_line(fd)) != NULL)
	{
		if (first == NULL)
			first = strdup(str);
		write(1, str, strlen(str));
		free(str);
	}
	write(1, "\n1º buffer: ", 14);
	write(1, first, strlen(first));
	free(first);
	close(fd);
	return (0);
}