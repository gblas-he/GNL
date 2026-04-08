/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 20:43:15 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/08 15:56:32 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char *str;
	//__attribute__((unused)) char *first = NULL;
	int count;
	int fd;
	
	count = 0;
	fd = open("ex.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("error");
		return (1);
	}
	while ((str = get_next_line(fd)) != NULL)
	{
		// 		if (first == NULL)
		//			first = strdup(str); 
		count++;
		printf("main: [%d] %s\n", count, str);
		free(str);
	}
	// printf("\n1º buffer: %s", first);
	// free(first);
	close(fd);
	return (0);
}