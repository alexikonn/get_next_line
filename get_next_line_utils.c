/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:35 by alegesle          #+#    #+#             */
/*   Updated: 2025/09/01 15:37:33 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*build_line(char **line_ptr) //THISSSSW!!!!! function I took out of get_next_line,  this function is used when new-line-character is found
{	
	size_t	sub_len; //PUT THIS FUNCTION IN UTILS FIRST; BECAUSE IT'S THE MOST IMPORTANT & BEFORE THAT THE PROTOTYPES OF THE FUNCTIONS THAT ARE usED BUT NOT IN THE HEADER
	//length of the substring
	 ////line is initialized to an empty string and then line becomes the new string through ft_strjoin (joins line and buffer)
	char	*free_line;
	char	*sub_line;
	char	*line;

	line = *line_ptr;
	if (ft_strchr(line, '\n') != NULL)
	{
		sub_len = ft_strchr(line, '\n') - line +1; //sub_len is as long as the pointer to line until new line character is found 
	//(f.ex. first character of a string in BUFFER_SIZE) minus pointer to current line + 1 for the new line character
		sub_line = ft_substr(line, 0, sub_len); // sub_line is the new string which is build out of a line until a newline character (including it)
		free_line = line;
		*line_ptr = ft_substr(line, sub_len, BUFFER_SIZE);
		//line saves the substr which is the rest from sub_line and as line is a static variable, in the next call we start with the saved part
		free(free_line);
	}//check if line is an empty string, so it returns NULL, because NULL [i] -> segfault. i can´t iterate through a null pointer
	else
	{	
		sub_line = line;
		*line_ptr = NULL;
	}
	return (sub_line); //returns the new line (sub_line) including the new line character (compiled, worked)
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return(NULL);
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size) //STATIC FUNCTION
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

// wrote a while loop for finding out the length of buffer and saving it in the variable len
// ft_strdup duplicates the buffer and I created buffer_dup, which contains the copied buffer
// it was nessasry to create a buffer_dup, because buffer is a local variable and is not working outside the function
//added len < BUFFER_SIZE to the while loop, which makes rue that only as many carachters are copied as the BUFFER_SIZE. 
// -> before that, while printing there were more characters than BUFFER_SIZE, because len was always searching for '\0'

//WHAT happens with ft_strjoin when one s is NULL, handle like empty strings??
char	*ft_strjoin(const char *s1, const char *s2)
{ 
	char	*result;
	int		len1;
	int		len2;
	int		i;

	len1 = 0;
	while (s1 != NULL && s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2 != NULL && s2[len2] != '\0')
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
	while (s1 != NULL && s1[++i] != '\0')
		result[i] = s1[i];
	i = -1;
	while (s2 != NULL && s2[++i] != '\0')
		result [i + len1] = s2[i];
	return (result);
	//starting with i = -1, because we increase i in the while conditions first, so that means s[i] goes to 1 and does not work with the char on the 0 positions
}
//created this function specialized for getnextline
//it joins string 1 and string 2 until the null-character
//learned about the difference between ++i and i++
//str_dup is not nessessary, because strjoin can also a join a string with an empty string

//function copies only max of size characters of a string src into dst,
//it null-terminates the dst and returns the length of the full string s1

char	*ft_substr(char const *s, unsigned int start, size_t len) //STATIC FUNCTION; NOT IN HEADER
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


