#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*init_buffer(char *buffer);
char		*free_buffer(char *buffer);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);

#endif
