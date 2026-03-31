/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblas-he <gblas-he@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:18:10 by gblas-he          #+#    #+#             */
/*   Updated: 2026/03/31 21:09:55 by gblas-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H



#include <fcntl.h>
#include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);

#endif