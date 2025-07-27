/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/07/27 21:46:30 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{	
	int		fd;
	char	buffer[50];
	int		count;

	count = 0;
	fd = open("./freddy.txt", O_RDONLY);
	while (count < 3)
	{
		count++;
		read(fd, buffer, 10);
		printf("First 10 bytes: %s\n", buffer);
	}
	close(fd);
	return (0);
}