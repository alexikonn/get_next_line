/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:29:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/19 12:02:22 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{	
	int		fd;
	int		count;
	char	*line;
	int		new;

	count = 0;
	fd = open("./file.txt", O_RDONLY);

	//printf("%d\n", fd);

	/*if (fd < 0)
	{
		printf("Error\n");
		return (1);
	}*/
	while (count < 3)
	{
		count++;
		line = get_next_line(fd);
		new = has_new_line(line);
		printf("\nBUFFER_SIZE: %d\n", BUFFER_SIZE);
		printf("buffer: %s\n", line);
		printf("has_new_line: %d\n", new);
	}
	close(fd);
	return (0);
}

//printing the BUFFER_SIZE & the buffer & if the buffer has a new_line_charachter
// if yes: 1 - if not: 0