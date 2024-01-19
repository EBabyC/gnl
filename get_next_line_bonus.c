/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:06:39 by elichan           #+#    #+#             */
/*   Updated: 2024/01/15 12:33:41 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *store)
{
	int		i;
	char	*line;

	i = 0;
	if (!store[i])
		return (NULL);
	line = malloc(sizeof(char) * (ft_line_len(store) + 2));
	if (!line)
		return (NULL);
	str_cpy(line, store);
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
			free(buff);
			return (NULL);
		}
		buff[reading_idx] = '\0';
		store = ft_strjoin(store, buff);
	}
	free(buff);
	return (store);
}

char	*free_stash(char *store)
{
	int		i;
	int		j;
	char	*new_stash;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	j = 0;
	while (store[i])
		new_stash[j++] = store[i++];
	new_stash[j] = '\0';
	free(store);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store[900];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 899)
		return (NULL);
	store[fd] = read_and_join(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = get_line(store[fd]);
	store[fd] = free_stash(store[fd]);
	return (line);
}
/*
int main()
{
	int    fd;
	char *line;

	fd = open("testfile", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
}
*/