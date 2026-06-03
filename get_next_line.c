/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:12:44 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/02 11:12:48 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_stash(int fd, char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_stash(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	stash = clean_up(stash);
	return (line);
}

static char	*read_and_stash(int fd, char *stash)
{
	ssize_t	bytes;
	char *buf;
	char *temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 0;
	while ((!stash || !ft_strchr(stash, '\n')) 
		&& (bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		temp = stash;
		stash = ft_strjoin(stash, buf);
		free (temp);
	}
	free (buf);
	if (bytes < 0)
	{
		free(stash);
		return (NULL);
	}
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	int		j;
	char	*ptr;	

	i = 0;
	if (!stash || !*stash)
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while(j < i)
	{
		ptr[j] = stash[j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char *clean_up(char *stash)
{
	int		i;
	int 	j;
	char	*ptr;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\0')
	{
		free (stash);
		return (NULL);
	}
	i++;
	ptr = malloc(ft_strlen(stash + i) + 1);
	if (!ptr)
		return (NULL);
	j = 0;
	while (stash[i] != '\0')
		ptr[j++] = stash[i++];
	ptr[j] = '\0';
	free (stash);
	return (ptr);
}

	
	
