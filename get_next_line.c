/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/22 21:36:12 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

// wrote a while loop for finding out the length of buffer and saving it in the variable len
// ft_strdup duplicates the buffer and I created buffer_dup, which contains the copied buffer
// it was nessasry to create a buffer_dup, because buffer is a local variable and is not working outside the function
//added len < BUFFER_SIZE to the while loop, which makes rue that only as many carachters are copied as the BUFFER_SIZE. 
// -> before that, while printing there were more characters than BUFFER_SIZE, because len was always searching for '\0'

int	has_new_line(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
//created this function, to check if the buffer has a new-line character (\n)
//checked it with the main

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	int		len1;
	int		len2;
	int		i;

	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	result[len1 + len2] = '\0';
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		result [i + len1] = s2[i];
	return (result);
}
//created this function specialized for getnextline
//it joins string 1 and string 2 until the null-character
//learned about the difference between ++i and i++
//deleted ft_strdup and replaced it with ft_strjoin

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE + 1)
	{
		buffer[i] = 0;
		i++;
	}
	while (has_new_line(line) == 0)
	

	

	//read(fd, buffer, BUFFER_SIZE);
	//line = ft_strjoin(buffer, "");
	return (line);
}

//started a while loop, which checks if there is a new line charackter in the line variable,
//which is the joined string


// Buffer_SIZE is the Macro for the size of buffer, which will be added to compile during evaluation
//line = variable wihich contains the joined strings, if one of the string is an empty string, this is how it is portraited ""

//while compiling with different BUFFER_SIZES we found out, that len of the string should be < BUFFER_SIZE

// next to-do: implement has_new_line function into get_next_line to check, if buffer has a '\n' or not,
// -> if yes, it should give the line, when not, it should search as long as it finds one