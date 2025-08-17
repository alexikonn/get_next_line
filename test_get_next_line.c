/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:29:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/17 19:10:03 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{	
	int		fd;
	char	buffer[50];
	int		count;

	count = 0;
	fd = open("./file.txt", O_RDONLY);

	/*if (fd < 0)
	{
		printf("Error\n");
		return (1);
	}*/
	while (count < 3)
	{
		count++;
		get_next_line(fd);
		printf("First 10 bytes: %s\n", buffer);
	}
	close(fd);
	return (0);
}