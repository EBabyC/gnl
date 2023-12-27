/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:52:03 by elichan           #+#    #+#             */
/*   Updated: 2023/12/21 13:26:24 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *store)
{
	int			i;
	char		*line;

	i = 0;
	if (!store[i])
		return (NULL);
	line = malloc(sizeof(char) * (ft_line_len(store) + 2));
	if (!line)
		return (NULL);
	str_cpy(line, store)
	return (line);
}

char	*read_and_join(int fd, char *store)
{
	char	*buff;
	int		reading_idx;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	reading_idx = 1;
	while (!ft_strchr(store, '\n') && reading_idx != 0)
	{
		reading_idx = read(fd, buff, BUFFER_SIZE);
		if (reading_idx == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[reading_idx] = '\0';
		store = ft_sjoin(store, buff);
	}
	free (buff);
	return (store);
}

