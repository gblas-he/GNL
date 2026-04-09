/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 16:53:40 by gblas-he          #+#    #+#             */
/*   Updated: 2026/04/09 12:57:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

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

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	if (!s)
		return (NULL);
	cc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
		str[len1++] = s2[i++];
	return (str);
}
