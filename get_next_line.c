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

#inlcude "get_next_line.h"

static char	*stash;
ssize_t		bytes_read;
char		*buf;

buf = malloc(BUFFER_SIZE + 1);
if (!buf)
	return (NULL);
if (stash == NULL)
	stash = malloc(1);
stash[0] = '\0';
while (!ft_strchr(stash, '\n'))
{
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
		break ;
	buf[bytes_read] = '\0';
	temp = stash;
	stash = ft_strjoin(stash, buf);
	free (temp);
}


