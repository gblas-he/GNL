/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:43:15 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/09 12:59:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*str;
	int		count;
	int		fd;

	count = 0;
	fd = open("ex.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		return (1);
	}
	
	while ((str = get_next_line(fd)) != NULL)
	{
		count++;
		printf("main: [%d] %s\n", count, str);
		free(str);
	}
	close(fd);
	return (0);
}