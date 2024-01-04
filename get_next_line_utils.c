/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:58:17 by elichan           #+#    #+#             */
/*   Updated: 2024/01/04 12:37:52 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Strlen returns the lenght of the string (without '\0')
strchr checks the string until it finds the 1st '\0', returns a pointer to
the end of ths string */

#include "get_next_line.h"

size_t	ft_strlen(const char *store)
{
	size_t	i;

	i = 0;
	if (!store)
		return (0);
	while (store[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *store, int c)
{
	int	i;

	i = 0;
	if (!store)
		return (NULL);
	if (c == '\0')
		return ((char *)&store[ft_strlen(store)]);
	while (store[i] != '\0')
	{
		if (store[i] == (char)c)
			return ((char *)&store[i]);
			i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *store, char *buff)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!store)
	{
		store = malloc(sizeof(char) * 1);
		if (!store)
			return (NULL);
		store[0] = '\0';
	}
	if (!buff)
		return (NULL);
	dest = malloc(sizeof(char) * ((ft_strlen(store) + ft_strlen(buff)) + 1));
	if (!dest)
		return (NULL);
	while (store[++i] != '\0')
		dest[i] = store[i];
	while (buff[j] != '\0')
		dest[i++] = buff[j++];
	dest[ft_strlen(store) + ft_strlen(buff)] = '\0';
	free(store);
	return (dest);
}

void	str_cpy(char *line, char *store)
{
	int	i;

	i = 0;
	while (store[i] && store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		line [i] = store[i];
		i++;
	}
	line[i] = '\0';
}

size_t	ft_line_len(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
			i++;
	return (i);
}
