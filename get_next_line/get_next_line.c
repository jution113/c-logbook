#include "get_next_line.h"

char	*read_to_buffer(int fd, char *buffer, ssize_t *bytes)
{
	char	*chunk;
	char	*tmp;

	chunk = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (chunk == NULL)
		return (NULL);
	*bytes = read(fd, chunk, BUFFER_SIZE);
	if (*bytes == 0)
	{
		free(chunk);
		return (buffer);
	}
	else if (*bytes < 0)
	{
		free(chunk);
		free(buffer);
		return (NULL);
	}
	chunk[*bytes] = '\0';
	tmp = ft_strjoin(buffer, chunk);
	free(chunk);
	free(buffer);
	if (tmp == NULL)
		return (NULL);
	return (tmp);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*trim_left(char *buffer)
{
	char	*trimmed;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	i++;
	trimmed = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (trimmed == NULL)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i] != '\0')
		trimmed[j++] = buffer[i++];
	trimmed[j] = '\0';
	free(buffer);
	return (trimmed);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = init_buffer(buffer);
	if (buffer == NULL)
		return (NULL);
	bytes = 1;
	while (buffer != NULL && ft_strchr(buffer, '\n') == NULL && bytes > 0)
		buffer = read_to_buffer(fd, buffer, &bytes);
	if (buffer == NULL || buffer[0] == '\0')
	{
		buffer = free_buffer(buffer);
		return (NULL);
	}
	line = get_line(buffer);
	if (line == NULL)
	{
		buffer = free_buffer(buffer);
		return (NULL);
	}
	buffer = trim_left(buffer);
	return (line);
}
