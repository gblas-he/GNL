/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:53:16 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/31 21:17:38 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(3 + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

int	main(void)
{
	__attribute__((unused)) int fd = open("ex.txt", O_RDONLY);
	__attribute__((unused)) char *str;
	__attribute__((unused)) char *first = NULL;
	__attribute__((unused)) int count = 0;
	if (fd == -1)
	{
		printf("error");
		return (-1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		if (first == NULL)
			first = strdup(str);
		count++;
		printf("[%d] %s\n", count, str);
		free(str);
	}
	printf("\n1º buffer: %s", first);
	free(first);
	close(fd);
	return (0);
}