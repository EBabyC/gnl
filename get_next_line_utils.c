/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elichan < elichan@student.42.fr >          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 11:58:17 by elichan           #+#    #+#             */
/*   Updated: 2023/12/21 13:09:33 by elichan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_slen(const char *store)
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
		return ((char *)&store[ft_slen(store)]);
	while (store[i] != '\0')
	{
		if (store[i] == (char c))
			return ((char *)&store[i]);
			i++;
	}
	return (NULL);
}

char	*ft_strjoin(const char *, char *buff)
{
	char	dest;
	size_t i;
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
	
}