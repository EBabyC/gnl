/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:44:32 by elichan           #+#    #+#             */
/*   Updated: 2024/01/04 14:53:03 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Definition of the get_next_line function with the necessary headers
for memory allocation, string maipulation etc...
Definition of a constant buffer size of 5
Declaration of 2 local variables char *line and char *store
Copy of content of store to line
*/

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *store, int c);
char	*ft_strjoin(char *store, char *buff);
size_t	ft_strlen(const char *s);
size_t	ft_line_len(char *line);
void	str_cpy(char *line, char *store);

#endif
