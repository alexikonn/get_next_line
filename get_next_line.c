/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/11/05 22:16:17 by alegesle         ###   ########.fr       */
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
	char		*free_line;
	ssize_t		read_ret;

	while (ft_strchr(remainder, '\n') == NULL)
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
			buffer[i++] = 0;
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret == 0)
			break ;
		else if (read_ret == -1)
		{
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		free_line = remainder;
		remainder = ft_strjoin(remainder, buffer);
		free(free_line);
	}
	return (build_line(&remainder));
}
