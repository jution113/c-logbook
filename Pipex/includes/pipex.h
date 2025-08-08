/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:00:55 by suju              #+#    #+#             */
/*   Updated: 2025/08/07 16:00:57 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../Libft/libft.h"

void	error_exit(const char *msg);
void	free_ptr_arr(char **ptr_arr);
char	*find_executable_path(char *cmd_name, char **cmd_path_arr);
char	*find_cmd_path(char *cmd_name, char *envp[]);

#endif
