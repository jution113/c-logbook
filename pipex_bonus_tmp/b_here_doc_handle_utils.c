/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_here_doc_handle_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 00:10:54 by suju              #+#    #+#             */
/*   Updated: 2025/08/12 00:10:56 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_pipex.h"

char    *find_new_line(char *buffer)
{
    while (*buffer)
    {
        if (*buffer == '\n')
            return (buffer);
        buffer++;
    }
    return (NULL);
}

char    *join_and_free(char *save, char *buffer)
{
    char    *tmp;

    tmp = ft_strjoin(save, buffer);
    free(save);
    return (tmp);
}

char    *extract_line(char **save)
{
    char    *line;
    char    *new_line_pos;
    char    *tmp;

    new_line_pos = find_new_line(*save);
    if (!new_line_pos)
    {
        line = ft_strdup(*save);
        free(*save);
        *save = NULL;
        return (line);
    }
    line = ft_substr(*save, 0, (new_line_pos - *save) + 1);
}

char    *get_next_line_here_doc(int fd)
{
    static char *save;
    char    buffer[BUFFER_SIZE + 1];
    int     bytes_read;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    bytes_read = 1;
    while (!find_new_line(save) && bytes_read > 0)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0)
        {
            free(save);
            save = NULL;
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        if (!save)
            save = ft_strdup("");
        save = join_and_free(save, buffer);
    }
    if (!save || *save == '\0')
    {
        free(save);
        save = NULL;
        return (NULL);
    }
    return (extract_line(&save));
}
