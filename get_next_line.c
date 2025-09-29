/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/09/29 21:11:17 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//as long as \n is not found, 
char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line = NULL;
	size_t		i;
	char		*sub_line;
	char		*free_line;

	if (fd < 0)
		return (NULL);
	while (ft_strchr(line, '\n') == NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[i] = 0;
			i++;
		}
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
			break ;
		free_line = line;
		line = ft_strjoin(line, buffer);
		free(free_line);
	}
	sub_line = build_line(&line);
	return (sub_line);
}
