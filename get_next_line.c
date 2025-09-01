/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/09/01 15:33:52 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line = NULL;
	//static variable allocates memory, its value is the rest which comes after the new-line-character - LEARN MORE ABOUT StatIC VARIABLES
	size_t		i;
	char		*sub_line;
	//the new string which is the subline until the new line character
	char		*free_line;

	while (ft_strchr(line, '\n') == NULL)
	//as long as new line character is not found
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[i] = 0;
			i++;
		} //every i in buffer is initialized to zero, to make sure everything inside is overwrite by zero
		if (read(fd, buffer, BUFFER_SIZE) == 0) //CHECK EDGDE CASE IF LAST CHARACTER IN FILE IS NEW LINE CHARACHTER
			break ;//read only read as long as the end of file is reached, when this happens, there is a function break
		free_line = line;
		line = ft_strjoin(line, buffer);
		free(free_line);
		//line is always the joined string starts at the first char which is in the text file and joins everything that is read in BUFFER_SIZE
	}
	sub_line = build_line(&line);
	return (sub_line);
}
