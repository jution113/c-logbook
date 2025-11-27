/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suju <suju@student.42gyeongsan.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:00:30 by suju              #+#    #+#             */
/*   Updated: 2025/08/07 16:00:33 by suju             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/m_pipex.h"

void	validate_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("invalid argc: EXP ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_exit(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
}

void	handle_cmd_error(char *cmd_name, char **cmd_argv)
{
	int	error_code;

	error_code = 1;
	if (is_path_command(cmd_name))
	{
		if (access(cmd_name, F_OK) == -1)
		{
			ft_putstr_fd("command not found: ", 2);
			error_code = 127;
		}
		else if (access(cmd_name, X_OK) == -1)
		{
			ft_putstr_fd("permission denied: ", 2);
			error_code = 126;
		}
	}
	else
	{
		ft_putstr_fd("command not found: ", 2);
		error_code = 127;
	}
	ft_putstr_fd(cmd_name, 2);
	ft_putstr_fd("\n", 2);
	free_ptr_arr(cmd_argv);
	exit(error_code);
}

void	handle_file_error(char *file_name, int error_code)
{
	if (error_code == ENOENT)
		ft_putstr_fd("no such file or directory: ", 2);
	else if (error_code == EACCES)
		ft_putstr_fd("permission denied: ", 2);
	else
		error_exit("open", EXIT_FAILURE);
	ft_putstr_fd(file_name, 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	free_ptr_arr(char **ptr_arr)
{
	int	i;

	i = 0;
	while (ptr_arr[i])
	{
		free(ptr_arr[i]);
		i++;
	}
	free(ptr_arr);
}
