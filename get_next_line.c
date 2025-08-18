/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/18 23:29:21 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (src[j] && j < size -1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
// copied function from libft

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s, len + 1);
	return (copy);
}
// wrote a while loop for finding out the length of buffer and saving it in the variable len
// ft_strdup duplicates the buffer and I created buffer_dup, which contains the copied buffer
// it was nessasry to create a buffer_dup, because buffer is a local variable and is not working outside the function

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*buffer_dup;
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer[i] = 0;
		i++;
	}
	read(fd, buffer, BUFFER_SIZE);
	buffer_dup = ft_strdup(buffer);
	return (buffer_dup);
}
// Buffer_SIZE is the Macro for the size of buffer, which will be added to compile during evaluation

//to do: test and compile with different buffer sizes with the -D flag and without

/*smth is not working with -D BUFFER_SIZE=42 (First 10 bytes: Guten Tag, hallo
haben Sie sich schon ents�F
First 10 bytes: chieden,
was Sie heute bestellen wollen?
First 10 bytes: */