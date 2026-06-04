/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:12:58 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/03 18:04:36 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *stash, char *buf)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	ptr = malloc(ft_strlen(stash) + ft_strlen(buf) + 1);
	if (!ptr)
		return (free(stash), NULL);
	i = 0;
	while (stash[i])
	{
		ptr[i] = stash[i];
		i++;
	}
	j = 0;
	while (buf[j])
		ptr[i++] = buf[j++];
	ptr[i] = '\0';
	return (free(stash), ptr);
}

char	*ft_strchr(char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}
