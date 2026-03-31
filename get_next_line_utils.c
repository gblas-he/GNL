/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:53:40 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/31 21:09:57 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char *tmp;
	size_t i;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	tmp = malloc(size * nmemb);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < size * nmemb)
		tmp[i++] = '\0';
	return (tmp);
}