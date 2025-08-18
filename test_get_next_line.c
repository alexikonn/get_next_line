/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:29:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/18 21:36:24 by alegesle         ###   ########.fr       */
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
		printf("First 10 bytes: %s\n", line);
	}
	close(fd);
	return (0);
}