/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 15:53:16 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/28 21:32:07 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd)
{
}

int	main(void)
{
	int fd = open("ex.txt", O_RDONLY);
	char *str;
	while ((str = get_next_line(fd)) != NULL)
	{
		write(1, str, strlen(str));
		free(str);
	}
	close(fd);
	return (0);
}