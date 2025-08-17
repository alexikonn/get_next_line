/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/17 19:31:09 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len =
	copy = malloc(ft_strlen(s) + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}

char	*get_next_line(int fd)
{
	char	buffer[50];
	char	*buffer_dup;

	buffer_dup = ft_strdup(buffer);
	read(fd, buffer, 10);
	return (buffer);
}
