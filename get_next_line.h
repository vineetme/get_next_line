#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
# endif

size_t		ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*extract_line(char *stash);
char		*clean_up(char *stash);
char		*ft_strjoin(char *stash, char *buf);
size_t		ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, char *src, size_t dstsize);
char		*ft_strchr(char *str, int c);


#endif
