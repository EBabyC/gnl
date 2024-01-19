/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:52:03 by elichan           #+#    #+#             */
/*   Updated: 2024/01/18 12:56:07 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//getline extracts line of store & allocates mem to store, copies
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
			free (buff);
			return (NULL);
		}
		buff[reading_idx] = '\0';
		store = ft_strjoin(store, buff);
	}
	free (buff);
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
	{
		new_stash[j++] = store[i++];
	}
	new_stash[j] = '\0';
	free(store);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_and_join(fd, store);
	if (!store || store[0] == 0)
	{
		free(store);
		store = NULL;
		return (NULL);
	}
	line = get_line(store);
	store = free_stash(store);
	return (line);
}
/*
int	main(void)
{
	int			fd;
	char		*line;

	fd = open("tests.txt", O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	free(line);
}
*/
