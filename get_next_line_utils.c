/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:23:35 by alegesle          #+#    #+#             */
/*   Updated: 2025/09/25 12:16:25 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

char	*build_line(char **line_ptr)
{
	size_t	sub_len;
	char	*free_line;
	char	*sub_line;
	char	*line;

	line = *line_ptr;
	if (ft_strchr(line, '\n') != NULL)
	{
		sub_len = ft_strchr(line, '\n') - line + 1;
		sub_line = ft_substr(line, 0, sub_len);
		free_line = line;
		*line_ptr = ft_substr(line, sub_len, BUFFER_SIZE); // could the issue be that the remainder is always in BUFFER_SIZE?
		free(free_line);
	}
	else
	{
		sub_line = line;
		*line_ptr = NULL;
	}
	return (sub_line);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
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
	result = malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	result[len1 + len2] = '\0';
	i = -1;
	while (s1 != NULL && s1[++i] != '\0')
		result[i] = s1[i];
	i = -1;
	while (s2 != NULL && s2[++i] != '\0')
		result [i + len1] = s2[i];
	return (result);
}

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
