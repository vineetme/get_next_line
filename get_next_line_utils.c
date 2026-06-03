/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/02 11:12:58 by vmeharia          #+#    #+#             */
/*   Updated: 2026/06/03 15:49:41 by vmeharia         ###   ########.fr       */
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
	size_t	len1;
	size_t	len2;

	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	len1 = ft_strlen(stash);
	len2 = ft_strlen(buf);
	ptr = malloc (len1 + len2 + 1);
	if (!ptr)
	{
		free (stash);
		return (NULL);
	}
	ft_strlcpy(ptr, stash, len1 + 1);
	ft_strlcat(ptr, buf, len1 + len2 + 1);
	free (stash);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	src_len = ft_strlen(src);
	j = 0;
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
		dst_len++;
	if (dstsize == 0)
		return (src_len);
	if (dstsize == dst_len)
		return (dstsize + src_len);
	else
	{
		while ((dstsize - 1) > (dst_len + j) && src[j] != '\0')
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = '\0';
		return (dst_len + src_len);
	}
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
