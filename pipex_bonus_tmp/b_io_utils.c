/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:24:39 by suju              #+#    #+#             */
/*   Updated: 2025/08/11 17:24:40 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_pipex.h"

void    handle_here_doc(char *limiter)
{
    char    *line;
    int     limiter_len;

    limiter_len = ft_strlen(limiter);
    while (1)
    {
        ft_putstr_fd("heredoc> ", 1);
        line = get_next_line_here_doc(0);
        
    }
}

void    setup_io_redirection(int pipe_cnt, int pipe_idx, int **pipes)
{
    if (pipe_idx > 0)
    {
        if (dup2(pipes[pipe_idx - 1][0], 0) == -1)
            // TODO: 여기서 에러를 처리하는 것이 맞는가?
    }
    if (pipe_idx < pipe_cnt - 1)
    {
        if (dup2(pipes[pipe_idx][1], 1) == -1)
            // TODO: 여기서 에러를 처리하는 것이 맞는가?
    }
}

void    setup_input_redirection(char *argv[], int is_here_doc)
{
    char    *infile;
    int     fd;

    if (is_here_doc)
    {
        infile = argv[2];
        handle_here_doc(infile);
    }
    else
    {
        infile = argv[1];
        fd = open(infile, O_RDONLY);
        if (fd == -1)
            // TODO: 여기서 에러를 처리하는 것이 맞는가?
        if (dup2(fd, 0) == -1)
            // TODO: 여기서 에러를 처리하는 것이 맞는가?
        close(fd); // TODO: close 실패 시에 처리를 해줘야 하는 것이 아닌가?
    }
}

void    setup_output_redirection(char *argv[], int is_here_doc)
{
    char    *outfile;
    int     argc;
    int     fd;

    argc = 0;
    while (argv[argc])
        argc++;
    outfile = argv[argc - 1];
    if (is_here_doc)
        fd = open(outfile, O_RDONLY | O_CREAT | O_APPEND, 0644);
    else
        fd = open(outfile, O_RDONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
        // TODO: 에러 처리
    if (dup2(fd, 1)== -1)
        // TODO: 에러 처리
    close(fd); // TODO: 에러처리를 해줘야 하나?
}
