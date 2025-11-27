/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_pipex.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:57:27 by suju              #+#    #+#             */
/*   Updated: 2025/08/11 17:57:29 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PIPEX_H
# define BONUS_PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// pipe
int     **create_pipes(int pipe_cnt);
void    close_pipes(int **pipes, int pipe_cnt);
void    free_pipes(int **pipes, int pipe_cnt);

// io
void    handle_here_doc(char *limiter);
void    setup_io_redirection(int pipe_cnt, int pipe_idx, int **pipes);
void    setup_input_redirection(char *argv[], int is_here_doc);
void    setup_output_redirection();

// util
void	validate_args_bonus(int argc);
int		is_here_doc_mode(char *arg);
int		get_cmd_count(int argc, char *argv[]);

void	free_ptr_arr(char **ptr_arr);

#endif
