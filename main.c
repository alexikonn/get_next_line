/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:29:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/09/25 11:50:13 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("./file.txt", O_RDONLY);
	//fd = -1;
	printf("%s", get_next_line(fd));
	/*printf("%d\n", fd);
	if (fd < 0)
	{
		printf("Error\n");
		return (1);
	}*/
	//printf("\nBUFFER_SIZE: %d\n\n", BUFFER_SIZE);
	
	
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	//printf("\n");

	close(fd);
	return (0);
}

//printing the BUFFER_SIZE & the buffer & if the buffer has a \n
// if yes: 1 - if not: 0

//NULL[i] -> segfault 