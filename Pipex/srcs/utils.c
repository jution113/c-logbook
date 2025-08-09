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

#include "../includes/pipex.h"

void	validate_args(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("[Error] Expected: ./pipex file1 cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	error_exit(char *msg, int error_code)
{
	perror(msg);
	exit(error_code);
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

char	*find_executable_path(char *cmd_name, char **cmd_path_arr)
{
	char	*cmd_path;
	char	*tmp;
	int		i;

	i = 0;
	while (cmd_path_arr[i])
	{
		tmp = ft_strjoin(cmd_path_arr[i], "/");
		if (!tmp)
			return (NULL);
		cmd_path = ft_strjoin(tmp, cmd_name);
		free(tmp);
		if (!cmd_path)
			return (NULL);
		if (access(cmd_path, F_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char *cmd_name, char *envp[])
{
	char	**cmd_path_arr;
	char	*cmd_path;
	int		i;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH", 4))
		i++;
	cmd_path_arr = ft_split(envp[i] + 5, ':');
	if (!cmd_path_arr)
		return (NULL);
	cmd_path = find_executable_path(cmd_name, cmd_path_arr);
	free_ptr_arr(cmd_path_arr);
	return (cmd_path);
}
