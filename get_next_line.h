/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegesle <alegesle@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:25:19 by alegesle          #+#    #+#             */
/*   Updated: 2025/08/18 23:26:49 by alegesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h> //for read function
# include <stdlib.h> // malloc & free

char	*get_next_line(int fd);


#endif

//we learned about macros, how to define, checked with the Norm & why they are in the header file like this
// the 42 value is by default as subject says