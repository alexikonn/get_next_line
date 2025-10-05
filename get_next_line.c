/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/10/05 21:28:17 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//as long as \n is not found, 
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*remainder = NULL;
	size_t		i;
	char		*line;
	char		*free_line;

	if (fd < 0)
		return (NULL);
	while (ft_strchr(remainder, '\n') == NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[i] = 0;
			i++;
		}
		if (read(fd, buffer, BUFFER_SIZE) <= 0)// when invalid fd, read gives back -1, and gnl returns NULL for invalid fd
			break ;
		free_line = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free(free_line);
	}
	line = build_line(&remainder);
	return (line);
}
