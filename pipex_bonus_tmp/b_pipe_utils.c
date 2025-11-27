/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 15:49:13 by suju              #+#    #+#             */
/*   Updated: 2025/08/11 15:49:14 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_pipex.h"



int     **create_pipes(int pipe_cnt)
{
    int **pipes;
    int i;

    pipes = (int **)malloc(sizeof(int *) * pipe_cnt);
    if (!pipes)
        return (NULL); // TODO: error exit을 할 것인가? NULL을 반환하여 호출한 쪽에서 처리할 것인가?
    i = 0;
    while (i < pipe_cnt)
    {
        pipes[i] = (int *)malloc(sizeof(int *) * 2);
        if (!pipes[i] || pipe(pipes[i]) == -1)
            free_ptr_arr(pipes);
            return (NULL);
        i++;
    }
    return (pipes);
}

void    close_pipes(int **pipes, int pipe_cnt)
{
    int i;

    i = 0;
    while (i < pipe_cnt)
    {
        close(pipes[i][0]); // TODO: system call이 실패했을 때에는 어떻게 에러를 처리할 것인가?
        close(pipes[i][1]); // TODO: system call이 실패했을 때에는 어떻게 에러를 처리할 것인가?
        i++;
    }
}

void    free_pipes(int **pipes, int pipe_cnt)
{
    int i;

    i = 0;
    while (i < pipe_cnt)
    {
        free(pipes[i]);
        i++;
    }
    free(pipes);
}
