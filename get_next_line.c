/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:18:04 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/27 13:28:56 by alegesle         ###   ########.fr       */
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
//if yes: 1 as return value - if not: 0 as return value

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
	// find out length of s1 and s2
	result = malloc(len1 + len2 + 1);
	//allocate memory as much as sum of s1+s2 & one more for the null terminator
	if (!result)
		return (NULL);
	//checks if condition is true, so result is NULL (result == 0), it returns NULL immediately 
	result[len1 + len2] = '\0';
	//null-terminating the result string
	i = -1;
	while (s1[++i] != '\0')
		result[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		result [i + len1] = s2[i];
	return (result);
	//starting with i = -1, because we increase i in the while conditions first, so that means s[i] goes to 1 and does not work with the char on the 0 positions
}
//created this function specialized for getnextline
//it joins string 1 and string 2 until the null-character
//learned about the difference between ++i and i++
//str_dup is not nessessary, because strjoin can also a join a string with an empty string

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
//searches for the new line character in my string line
//if it is found, returns a pointer to that part in memory where it is found
//if it is not found, returns NULL

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
//function copies only max of size characters of a string src into dst,
//it null-terminates the dst and returns the length of the full string s1

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;

	s_len = 0;
	if (!s)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	sub_len = s_len - start;
	if (sub_len > len)
		sub_len = len;
	sub = malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_len + 1);
	return (sub);
}
//function creates a substring out of the string s beginning at the start point start
//the length of the substring is max len
//
char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
	size_t	i;
	char	*sub_line;
	//the new string which is the subline until the new line character
	size_t	sub_len;
	//length of the substring

	line = ""; ////line is initialized to an empty string and then line becomes the new string through ft_strjoin (joins line and buffer)
	while (has_new_line(line) == 0) //as long as new line character is not found
	{
		i = 0;
		while (i < BUFFER_SIZE + 1)
		{
			buffer[i] = 0;
			i++;
		} //every i in buffer is initialized to zero, to make sure everything inside is overwrite by zero
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			break; //read only read as long as the end of file is reached, when this happens, there is a function break
		line = ft_strjoin(line, buffer);
		//line is always the joined string starts at the first char which is in the text file and joins everything that is read in BUFFER_SIZE
	}
	sub_len = ft_strchr(line, '\n') - line +1; //sub_len is as long as the pointer to line until new line character is found 
	//(f.ex. first character of a string in BUFFER_SIZE) minus pointer to current line + 1 for the new line character
	sub_line = ft_substr(line, 0, sub_len); // sub_line is the new string which is build out of a line until a newline character (including it)
	return (sub_line); //returns the new line (sub_line) including the new line character (compiled, worked)
}
//TO DO: fix edge case, if end of file is reached and no more new-line character is found ORRRR when reaching the break point while read
//what happens with the part which is cut out after new line is found, because BUFFER_SIZE was bigger
//LEARN: what are local variables? when function ends, they are destroyed. it is not possible to give the adress(pointer) of a local variable back
//value is returned - LEARN MORE ABOUT LOCAL VARIABLES AND HOW THEY WORK



//NEW:

// -> learned that you can put a whole functioncall which returns a (return)value in a while loop in the paranthesis

// -> Buffer_SIZE is the Macro for the size of buffer, which will be added to compile during evaluation

// -> while compiling with different BUFFER_SIZES we found out, that len of the string should be < BUFFER_SIZE
